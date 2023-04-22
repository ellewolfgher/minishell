/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:28:15 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/21 21:32:20 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Handles pipes for the current command. If the command receives input from a
pipe, closes the writing end of the input pipe and duplicates the reading end
to stdin.
If the command sends output to a pipe, closes the reading end of the output
pipe and duplicates the writing end to stdout.

Example:
Assuming the command "ls -l | grep foo" is executed, this function will handle
the pipe between "ls -l" and "grep foo", allowing data to be passed between them.
*/
int	ft_handle_pipes(t_data *ms, t_execute *command)
{
	if (command->receives_from_pipe)
	{
		close(ms->pipe_in[1]);
		dup2(ms->pipe_in[0], STDIN_FILENO);
	}
	if (command->sends_to_pipe)
	{
		close(ms->pipe_out[0]);
		dup2(ms->pipe_out[1], STDOUT_FILENO);
	}
	return (0);
}
