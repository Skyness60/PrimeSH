/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:32:34 by sperron           #+#    #+#             */
/*   Updated: 2025/06/02 16:15:53 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"

static void initialize_data(t_data *data)
{
	data->chain = NULL;
	t_garb_c *garbage_collector = malloc(sizeof(t_garb_c));
	if (!garbage_collector)
	{
		perror("Failed to initialize garbage collector");
		exit(EXIT_FAILURE);
	}
	init_garbage_collector_chain(garbage_collector);
	data->chain = malloc(sizeof(t_chain));
	if (!data->chain)
	{
		perror("Failed to initialize chain");
		free_all(garbage_collector);
		exit(EXIT_FAILURE);
	}
	data->chain->next = NULL;
	data->chain->prev = NULL;
	data->chain->data = data;
	add_ptr(garbage_collector, data->chain);
}

static void main_loop(t_data *data)
{
	(void)data;
	ft_printf("Welcome to PrimeSH! Type 'exit' to quit or CTRL + D.\n");
	while (true)
	{
		// handle_signals();
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
