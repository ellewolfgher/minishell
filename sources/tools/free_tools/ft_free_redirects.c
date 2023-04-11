/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/11 16:57:55 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_redirects(t_redirect *this)
{
	t_redirect	*aux;

	aux = this;
	while (aux)
	{
		this = aux->next;
		ft_free((void **)&aux->target);
		ft_free((void **)&aux);
		aux = this;
	}
	return ;
}
