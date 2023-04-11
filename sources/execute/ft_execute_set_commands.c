/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_set_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:39:37 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/11 15:49:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Call each function that checks for a specific token type and returns the
//corresponding value to the command struct
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

//Checks for ERRTOKEN type on any token, which means that the executioner should
//stop, printing the error message and returning the command struct with the
//block_exec flag set to not execute the command
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

//Checks if the last token has been reached, so that the executioner knows when
//to stop
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

//Sets the command struct based on the tokens previously parsed
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
