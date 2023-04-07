/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_executioner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:49:16 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
void	ft_minishell_executioner(t_data *ms)
{
	if (!ft_pipe_check(ms))
		ft_exec_one_command(ms);
}
