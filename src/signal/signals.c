/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:24 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 16:54:14 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

static void	ft_signal_in_exec(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		g_signal_status = EXIT_CTRL_C;
	}
	else if (signal == SIGQUIT)
	{
		ft_printf("Quit (core dumped)\n");
		g_signal_status = EXIT_QUIT;
	}
}

static void	ft_signal_prompt(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
		g_signal_status = EXIT_CTRL_C;
	}
}

void	handle_signal(bool exec, bool heredoc, t_data *data)
{
	rl_event_hook = NULL;
	if (data->signals->extsh)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		if (exec)
			data->signals->extsh = false;
		else if (heredoc)
			data->signals->extsh = true;
		return ;
	}
	else if (exec)
		return (signal(SIGINT, ft_signal_in_exec), \
		signal(SIGQUIT, ft_signal_in_exec), \
		signal(SIGTSTP, ft_signal_in_exec), (void)heredoc);
	else if (heredoc)
		return (signal(SIGINT, SIG_IGN), \
		signal(SIGQUIT, SIG_IGN), \
		signal(SIGTSTP, SIG_IGN), (void)data);
	else
		return (signal(SIGINT, ft_signal_prompt), \
		signal(SIGQUIT, SIG_IGN), \
		signal(SIGTSTP, SIG_IGN), \
		data->signals->extsh = false, (void)data);
}
