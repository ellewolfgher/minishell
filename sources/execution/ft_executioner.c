/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executioner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 13:39:24 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_executioner(char **tokens)
{
	if (strcmp(tokens[0], "cd") == 0)
		command_cd(tokens);
	else if (strcmp(tokens[0], "pwd") == 0)
		command_pwd();
	// else if (strcmp(tokens[0], "exit") == 0)
	// 	exit(0);
	// else if (strcmp(tokens[0], "export") == 0)
	// 	command_export();
    // else if (strcmp(tokens[0], "unset") == 0)
	// 	command_unset();
    // else if (strcmp(tokens[0], "env") == 0)
	// 	command_env(tokens[1]);
	// else if (strcmp(tokens[0], "echo") == 0)
	// 	command_echo(tokens[1]);
}
