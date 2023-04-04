/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_executioner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:23:21 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 18:26:54 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_pipe_check(t_tokens *tokens)
{
	t_tokens	*head;

	head = tokens;
	while (head)
	{
		if (head->type == OPTOKEN && !ft_strcmp(head->value, "|"))
			return (1);
		head = head->next;
	}
	return (0);
}

void	ft_minishell_executioner(t_data *ms)
{
	if (ft_pipe_check(ms->tokens))
		ft_one_command(ms);
}
