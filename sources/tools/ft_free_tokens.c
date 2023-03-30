/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:10:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:28:33 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_tokens(t_tokens **tokens)
{
	t_tokens	*this;

	if (!*tokens)
		return ;
	while (*tokens)
	{
		this = *tokens;
		ft_free((void **)&(this->value));
		this->value = NULL;
		*tokens = (*tokens)->next;
		ft_free((void **)&this);
		this = NULL;
	}
	return ;
}
