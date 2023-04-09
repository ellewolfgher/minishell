/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_pipe_in.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:30:00 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:03:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Check if there is a pipe in the command block
int	ft_searchset_pipe_in(t_data *ms)
{
	t_tokens	*aux;

	aux = ft_tokens_iterate(ms);
	if (aux && aux->type == OPTOKEN)
		return (1);
	return (0);
}
