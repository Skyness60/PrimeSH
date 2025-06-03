/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:10:00 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 16:24:15 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"
#include "prompt.h"
#include "git.h"
#include "utils.h"

static void	append_git(char *prompt, int size, char *git_branch)
{
	(void)size;
	ft_strcat(prompt, "\001\e[38;5;35m\e[1m\002");
	ft_strcat(prompt, "\001\e[0m\e[48;5;35m\e[1;37m\002");
	ft_strcat(prompt, " 👾 ");
	ft_strcat(prompt, git_branch);
	ft_strcat(prompt, " ");
	ft_strcat(prompt, "\001\e[0m\e[38;5;35m\e[1m\002");
	ft_strcat(prompt, "\001\e[0m\002 ");
}

static void	append_dir(char *prompt, char *base)
{
	ft_strcat(prompt, "\001\e[38;5;208m\e[1m\002");
	ft_strcat(prompt, "\001\e[0m\e[48;5;208m\e[1;37m\002");
	ft_strcat(prompt, " 📁 ");
	ft_strcat(prompt, base);
	ft_strcat(prompt, " ");
	ft_strcat(prompt, "\001\e[0m\e[38;5;208m\e[1m\002");
	ft_strcat(prompt, "\001\e[0m\002 ");
}

void	build_prompt(char *prompt, int size, t_data *data)
{
	char		cwd[1024];
	char		*base;
	char		git_branch[128];
	const char	*status_color;
	char		status_buf[12];

	(void)data;
	getcwd(cwd, sizeof(cwd));
	base = strrchr(cwd, '/');
	if (base && *(base + 1))
		base++;
	else
		base = cwd;
	status_color = get_status_color();
	ft_itoa_buf(g_signal_status, status_buf);
	prompt[0] = '\0';
	ft_strcat(prompt, "\001");
	ft_strcat(prompt, status_color);
	ft_strcat(prompt, "\e[1m\002");
	ft_strcat(prompt, status_buf);
	ft_strcat(prompt, "\001\e[0m\002 ");
	append_dir(prompt, base);
	if (get_git_branch(git_branch, sizeof(git_branch)))
		append_git(prompt, size, git_branch);
}
