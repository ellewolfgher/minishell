/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_tokenize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:07:50 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 16:44:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parser_tokenize(t_data *ms)
{
	int			index;
	t_tokens	*temp;
	t_tokens	*previous;

	if (!ms->split || !ms->split[0])
		return ;
	index = 0;
	ms->tokens = ft_calloc(1, sizeof(*ms->tokens));
	temp = ms->tokens;
	temp->prev = NULL;
	while (ms->split[index])
	{
		temp->value = ft_strdup(ms->split[index]);
		if (ms->split[index + 1])
			temp->next = ft_calloc(1, sizeof(*ms->tokens));
		previous = temp;
		temp = temp->next;
		if (temp)
			temp->prev = previous;
		index++;
	}
	return ;
}
