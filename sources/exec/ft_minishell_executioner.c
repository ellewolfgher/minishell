/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_executioner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 19:13:06 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	ft_minishell_executioner(t_data *ms)
{
	if (!ft_pipe_check(ms))
		ft_exec_one_command(ms);
}
