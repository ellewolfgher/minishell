/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/09 19:49:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_print_commands(t_execute *command)
{
	int index;

	index = 0;
	printf("block_exec: %d\n", command->block_exec);
	printf("command: %s\n", command->command);
	printf("is_builtin: %d\n", command->is_builtin);
	while (command->args[index])
		printf("args: %s\n", command->args[index++]);
	// index = 0;
	// while (command->envp[index])
	// 	printf("envp: %s\n", command->envp[index++]);
	printf("receives_from_pipe: %d\n", command->receives_from_pipe);
	printf("sends_to_pipe: %d\n", command->sends_to_pipe);
	printf("error_to_print: %s\n", command->error_to_print);
}

//Ignore signals to avoid the shell from being killed while in a child process
//sets the t_execute struct with the commands to be executed and executes them
//after executing the commands, the t_execute struct is destroyed and the shell
//waits for the child processes to finish, then restores the signals and the
//original file descriptors
//Sets the state to CLEANSTATE
int	ft_minishell_exec_beta(t_data *ms)
{
	t_execute	*command;
	int			control;
	int			original_fds[2];

	control = 1;
	original_fds[0] = -1;
	original_fds[1] = -1;
	ft_signals_ignore();
	command = ft_execute_set_commands(ms);
	ft_print_commands(command);
	// while (control)
	// {
	// 	command = ft_execute_set_commands(ms);
	// 	control = ft_execute_loop(command, ms, original_fds);
	// 	destroy_exec_info(command);
	// 	if (ms->need_to_exit)
	// 		break ;
	// }
	// while (wait(&ms->exit_code) > 0)
	// 	continue ;
	// if (ms->exit_code >= 256)
	// 	ms->exit_code = ms->exit_code >> 8;
	ft_signals_init();
	ft_fds_restore(original_fds);
	ms->state = CLEANSTATE;
	return (0);
}

//Check if there is a pipe in the command
static int	ft_pipe_check(t_data *ms)
{
	t_tokens	*tokens;

	tokens = ms->tokens;
	while (tokens)
	{
		if (tokens->type == OPTOKEN && ft_strcmp(tokens->value, "|") == 0)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

//Call the right executioner accordind to the existence of a pipe
//Old version of the function, to keep up with BI tests, will be removed
void	ft_minishell_execute(t_data *ms)
{
	if (!ft_pipe_check(ms))
		ft_exec_one_command(ms);
}
