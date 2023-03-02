/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executioner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 14:58:12 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_executioner(char **tokens)
{
	if (strcmp(tokens[0], "cd") == 0)
		ft_command_cd(tokens);
	else if (strcmp(tokens[0], "pwd") == 0)
		ft_command_pwd();
	else if (strcmp(tokens[0], "exit") == 0)
		exit(0);
	else if (strcmp(tokens[0], "export") == 0)
		ft_command_export();
    else if (strcmp(tokens[0], "unset") == 0)
		ft_command_unset(tokens);
    else if (strcmp(tokens[0], "env") == 0)
		ft_command_env(tokens);
	else if (strcmp(tokens[0], "echo") == 0)
		ft_command_echo(tokens);
}
