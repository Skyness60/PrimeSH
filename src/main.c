/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:32:34 by sperron           #+#    #+#             */
/*   Updated: 2025/06/02 13:34:01 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"

static void initialize_data(t_data *data)
{
	data->chain = NULL;
}

static void main_loop(t_data *data)
{
	(void)data;
	ft_printf("Welcome to PrimeSH! Type 'exit' to quit or CTRL + D.\n");
	while (true)
	{
		char *input = readline("PrimeSH> ");
		if (!input || strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		add_history(input);
		printf("You entered: %s\n", input);
		free(input);
	}
	clear_history();
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	t_data	data;

	initialize_data(&data);
	main_loop(&data);
	return (0);
}
