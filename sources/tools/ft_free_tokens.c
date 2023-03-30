/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:10:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 11:27:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_tokens(t_tokens *tokens)
{
	t_tokens	*this;

	if (!tokens)
		return ;
	while (tokens)
	{
		this = tokens;
		ft_free(this->value);
		this->value = NULL;
		tokens = tokens->next;
		ft_free(this);
		this = NULL;
	}
	return ;
}
