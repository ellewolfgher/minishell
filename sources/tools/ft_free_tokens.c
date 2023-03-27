/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:10:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 17:15:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_free_tokens(t_data *ms)
{
	t_tokens	*this;

	if (!ms->tokens)
		return (NULL);
	while (ms->tokens)
	{
		this = ms->tokens;
		ft_free(this->value);
		this->value = NULL;
		ms->tokens = ms->tokens->next;
		ft_free(this);
		this = NULL;
	}
	return (NULL);
}
