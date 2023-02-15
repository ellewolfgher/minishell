/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:36:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/15 10:11:51 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void handle_signal(int signal_num) 
{
	if (signal_num == SIGINT) {
		pid_t pid = fork();

		if (pid == -1) 
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			// child process
			execl("/bin/bash", "bash", "-c", "./minishell &", NULL);
			exit(EXIT_FAILURE);
		} 
		else 
			printf("New process started with PID %d\n", pid);
	}
}

int main() 
{
	char *input;
	// Set up the signal handler
	struct sigaction sa;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	//done
	while ((input = readline("\033[1;32m$ \033[0m"))) 
	{
		printf("You entered: %s\n", input);
		free(input);
	}
	return 0;
}
