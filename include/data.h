/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:04:49 by sperron           #+#    #+#             */
/*   Updated: 2025/06/02 13:09:38 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "primesh.h"
# include "chain.h"

typedef struct s_chain	t_chain;

typedef struct s_data
{
	t_chain	*chain;
}				t_data;

#endif