/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:11:39 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 14:18:15 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H
# include <signal.h>
# include <stdio.h>
# include "primesh.h"

typedef struct s_data	t_data;

typedef struct s_signal
{
	bool	extsh;
}	t_signal;

void	handle_signal(bool exec, bool heredoc, t_data *data);

extern int				g_signal_status;
#endif