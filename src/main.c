/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperron <sperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:32:34 by sperron           #+#    #+#             */
/*   Updated: 2025/06/03 16:54:34 by sperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "primesh.h"
#include "prompt.h"
#include "git.h"
#include "utils.h"

int	g_signal_status = 0;

static void	initialize_data(t_data *data)
{
	data->chain = NULL;
	data->garbage = malloc(sizeof(t_garb_c));
	if (!data->garbage)
		exit(EXIT_FAILURE);
	init_garbage_collector_chain(data->garbage);
	data->chain = malloc(sizeof(t_chain));
	if (!data->chain)
		return (free_all(data->garbage), exit(EXIT_FAILURE));
	data->chain->next = NULL;
	data->chain->prev = NULL;
	data->chain->data = data;
	add_ptr(data->garbage, data->chain);
	data->signals = malloc(sizeof(t_signal));
	if (!data->signals)
	{
		perror("Failed to initialize signals");
		free_all(data->garbage);
		exit(EXIT_FAILURE);
	}
	data->signals->extsh = 0;
	add_ptr(data->garbage, data->signals);
	g_signal_status = 0;
}

static void	main_loop(t_data *data)
{
	char	*input;
	char	prompt[1024];

	input = NULL;
	ft_printf("Welcome to PrimeSH! Type 'exit' to quit or CTRL + D.\n");
	while (true)
	{
		handle_signal(0, 0, data);
		build_prompt(prompt, 1024, data);
		input = readline(prompt);
		if (!input || strcmp(input, "exit") == 0)
		{
			ft_printf("exit\n");
			clear_history();
			rl_clear_history();
			free(input);
			free_all(data->garbage);
			free(data->garbage);
			break ;
		}
		add_history(input);
		printf("You entered: %s\n", input);
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*local;

	(void)argc;
	(void)argv;
	(void)envp;
	local = setlocale(LC_ALL, "");
	initialize_data(&data);
	main_loop(&data);
	return (0);
}
