/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_categorize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:12:12 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 15:38:13 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Set the index of each token
static int	ft_index_tokens(t_tokens *tokens)
{
	t_tokens	*temp;
	int			i;

	temp = tokens;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	return (i);
}

//Categorize tokens as it's type
void	ft_parser_categorize(t_tokens *tokens)
{
	t_tokens	*aux;

	aux = tokens;
	ft_index_tokens(tokens);
	while (aux)
	{
		aux->type = ft_token_all(aux);
		if (aux->type == REDTOKEN || aux->type == OPTOKEN)
			if (ft_token_error(aux))
				aux->type = ERRTOKEN;
		aux = aux->next;
	}
}
