/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:10:00 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 14:23:49 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"
#include "git.h"

static int	is_valid_branch(char *branch)
{
	if (branch[0] == '\0')
		return (0);
	if (strncmp(branch, "fatal:", 6) == 0)
		return (0);
	return (1);
}

static void	setup_git_argv_env(char **argv, char **envp)
{
	argv[0] = "git";
	argv[1] = "rev-parse";
	argv[2] = "--abbrev-ref";
	argv[3] = "HEAD";
	argv[4] = NULL;
	envp[0] = NULL;
}

static int	exec_git_branch_child(int *pipefd, char **argv, char **envp)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	dup2(pipefd[1], 2);
	close(pipefd[1]);
	execve("/usr/bin/git", argv, envp);
	_exit(127);
}

static int	read_git_branch_output(int fd, char *buf, int size)
{
	ssize_t	r;

	r = read(fd, buf, size - 1);
	if (r > 0)
	{
		buf[r] = '\0';
		if (buf[r - 1] == '\n')
			buf[r - 1] = '\0';
		if (is_valid_branch(buf))
			return (1);
		buf[0] = '\0';
	}
	return (0);
}

int	get_git_branch(char *buf, int size)
{
	int		pipefd[2];
	pid_t	pid;
	char	*argv[5];
	char	*envp[1];
	int		ret;

	buf[0] = '\0';
	ret = 0;
	setup_git_argv_env(argv, envp);
	if (pipe(pipefd) == 0)
	{
		pid = fork();
		if (pid == 0)
			exec_git_branch_child(pipefd, argv, envp);
		else if (pid > 0)
		{
			close(pipefd[1]);
			ret = read_git_branch_output(pipefd[0], buf, size);
			close(pipefd[0]);
			waitpid(pid, NULL, 0);
		}
	}
	return (ret);
}
