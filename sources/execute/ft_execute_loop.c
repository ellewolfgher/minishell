/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:00:23 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:26:28 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	ft_execute_loop(t_execute *command, t_data *ms, int ogfds[2])
// {
// 	if (!command)
// 		return (0);
// 	if (command->block_exec)
// 	{
// 		write (2, command->error_to_print, ft_strlen(command->error_to_print));
// 		return (0);
// 	}
// 	ft_execute_redir_create(command);
// 	if (!command->receives_from_pipe && !command->sends_to_pipe)
// 	{
// 		exec_one_cmd(command, ms, ogfds);
// 		return (0);
// 	}
// 	else if (!ms->issue_exit)
// 		return (exec_multi(command, ms, ogfds));
// 	return (1);
// }
