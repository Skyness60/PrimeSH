/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:05:19 by sperron           #+#    #+#             */
/*   Updated: 2025/06/02 13:22:56 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAIN_H
# define CHAIN_H
# include "data.h"

typedef struct s_data	t_data;

typedef struct s_chain
{
	struct s_chain	*next;
	struct s_chain	*prev;
	t_data			*data;
}	t_chain;

#endif