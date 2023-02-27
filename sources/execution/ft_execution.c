/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/02/27 17:07:49 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h> 

void	execute_command(char *command)
{
	// Tokenize the command string into arguments
	char	*args[100];
	char	*arg;
	int		num_args;

	arg = command;
	num_args = 0;
	while (*arg != '\0')
	{
		while (*arg == ' ' || *arg == '\t' || *arg == '\n')
		{
			*arg++ = '\0';
		}
		args[num_args++] = arg;
		while (*arg != '\0' && *arg != ' ' && *arg != '\t' && *arg != '\n')
		{
			arg++;
		}
	}
	args[num_args] = NULL;

	// Handle built-in commands
	if (strcmp(args[0], "cd") == 0)
		command_cd(args[1]);
	else if (strcmp(args[0], "pwd") == 0)
		command_pwd();
	else if (strcmp(args[0], "exit") == 0)
		exit(0);
	else if (strcmp(args[0], "export") == 0)
		command_export();
    else if (strcmp(args[0], "unset") == 0)
		command_unset();
    else if (strcmp(args[0], "env") == 0)
		command_env(args[1])
}

int main() {
	char *command;
	while ((command = readline("\033[1;32m$ \033[0m"))) 
	{
		if (strlen(command) > 0)
		{
			execute_command(command);
		}
		printf("You entered: %s\n", command);
		free(command);
	}
	return 0;
}
 */