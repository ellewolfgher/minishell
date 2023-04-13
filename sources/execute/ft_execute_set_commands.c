/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_set_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:39:37 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:01:53 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Fills the given t_execute structure with values from the token list and the
environment variables list.

Example:
Given a t_execute structure and a token list representing the command
"echo 'Hello' | cat", the function fills the structure with flags and values to
handle the command, arguments, redirections, environment variables, and
pipe information.
*/
static void	ft_set_struct(t_data *ms, t_execute *command)
{
	command->receives_from_pipe = ft_searchset_pipe_in(ms);
	command->command = ft_searchset_command(ms, command);
	command->args = ft_searchset_arguments(ms);
	command->red_in = ft_searchset_input(ms);
	command->red_out = ft_searchset_output(ms);
	command->envp = ft_searchset_envvars(ms->env_vars);
	command->sends_to_pipe = ft_searchset_pipe_out(ms);
}

/*
Checks if there is an error token in the token list.
Sets the block_exec flag and error_to_print message in the t_execute structure
if an error token is found.
Returns 1 if an error token is found, otherwise 0.

Example:
If the token list contains an error token, the function sets the block_exec
flag to 1 and the error_to_print message to "Invalid syntax\n".
*/
static int	ft_check_errtoken(t_data *ms, t_execute *command)
{
	t_tokens	*aux;

	aux = ms->tokens;
	while (aux)
	{
		if (aux->type == ERRTOKEN)
		{
			command->block_exec = 1;
			command->error_to_print = ft_strdup("Invalid syntax\n");
			return (1);
		}
		aux = aux->next;
	}
	return (0);
}

/*
Checks if the last token in the token list has been processed.
Returns 1 if the last token has been processed, otherwise 0.

Example:
If the token list represents the command "echo 'Hello' | cat", the function
returns 1 after processing the 'cat' token.
*/
static int	ft_check_last_token(t_data *ms)
{
	t_tokens	*aux;

	aux = ms->tokens;
	while (aux->next)
		aux = aux->next;
	if (ms->tok_index > aux->index)
		return (1);
	return (0);
}

/*
Sets the commands to be executed based on the given token list and environment
variables list.
Returns a dynamically allocated t_execute structure containing the commands,
arguments, redirections, environment variables, and pipe information.

Example:
Given a token list representing the command "echo 'Hello' | cat", the function
returns a t_execute structure containing the flags and values needed to execute
the commands, arguments, redirections, environment variables, and
pipe information.
*/
t_execute	*ft_execute_set_commands(t_data *ms)
{
	t_execute	*command;

	if (ft_check_last_token(ms))
		return (NULL);
	command = ft_calloc(1, sizeof(t_execute));
	if (ft_check_errtoken(ms, command))
		return (command);
	ft_set_struct(ms, command);
	return (command);
}
