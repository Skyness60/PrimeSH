/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:04:49 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 11:47:14 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "primesh.h"

typedef struct s_chain	t_chain;

typedef struct s_garb_c	t_garb_c;

typedef struct s_signal	t_signal;

typedef struct s_data
{
	t_chain			*chain;
	t_garb_c		*garbage;
	t_signal		*signals;
}				t_data;

#endif