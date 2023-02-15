/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/15 18:13:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signal(int signal_num)
{
	pid_t	pid;

	if (signal_num == SIGINT)
	{
		pid = fork();
		if (pid == -1)
			perror("fork");
	}
}

int	main(void)
{
	char				*input;
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	input = readline("\033[1;32m$ \033[0m");
	while (input)
	{
		printf("You entered: %s\nPID:%d\n", input, getpid());
		free(input);
		input = readline("\033[1;32m$ \033[0m");
	}
	return (0);
}
