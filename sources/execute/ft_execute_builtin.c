/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:48:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/15 21:10:36 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Executes a built-in command based on the given command string. Takes a
t_execute structure, a t_data structure, and an array of original file
descriptors as parameters. Calls the appropriate built-in command function for
each supported command. Returns 0 after the execution.

Example:
Assuming the built-in command "echo" is executed with the argument 
"Hello, World!", this function will call ft_command_echo() and print
"Hello, World!" to the console.
*/
int	ft_execute_builtin(t_execute *command, t_data *ms, int og_fds[2])
{
	if (!command->sends_to_pipe && !command->receives_from_pipe)
	{
		if (ft_execute_redirects(command, og_fds, ms))
			return (ft_fds_restore(og_fds));
	}
	if (!ft_strcmp(command->command, "cd"))
		ft_command_cd(ms, command);
	if (!ft_strcmp(command->command, "echo"))
		ft_command_echo(ms, command);
	if (!ft_strcmp(command->command, "env"))
		ft_command_env(ms);
	if (!ft_strcmp(command->command, "exit"))
		ft_command_exit(ms, command);
	if (!ft_strcmp(command->command, "export"))
		ft_command_export(ms, command);
	if (!ft_strcmp(command->command, "pwd"))
		ft_command_pwd();
	if (!ft_strcmp(command->command, "unset"))
		ft_command_unset(ms, command);
	return (0);
}
