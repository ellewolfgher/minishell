/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 10:12:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int signal_num)
{
	if (signal_num == SIGINT)
		g_data->flag = 1;
}

int	main(void)
{
	char				*input;
	struct sigaction	sa;

	g_data = malloc(sizeof(t_data));
	if (g_data == NULL)
	{
		perror("Error: failed to allocate memory for g_data\n");
		exit(EXIT_FAILURE);
	}
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	input = readline("\033[1;32m$ \033[0m");
	while (input && !g_data->flag)
	{
		printf("You entered: %s\nPID:%d\n", input, getpid());
		free(input);
		printf("\n");
		input = readline("\033[1;32m$ \033[0m");
		g_data->flag = 0;
	}
	free(g_data);
	return (0);
}
