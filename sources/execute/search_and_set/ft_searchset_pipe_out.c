/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_pipe_out.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:26:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:03:32 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check if there is a pipe in the command block
int	ft_searchset_pipe_out(t_data *ms)
{
	t_tokens	*aux;

	aux = ft_tokens_iterate(ms);
	if (aux && aux->type == OPTOKEN)
	{
		aux = aux->next;
		ms->tok_index++;
	}
	while (aux)
	{
		if (aux->type == OPTOKEN)
			return (1);
		ms->tok_index++;
		aux = aux->next;
	}
	return (0);
}
