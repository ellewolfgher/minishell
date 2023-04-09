/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redirects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:54:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 18:55:24 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_execute_redir_create(t_execute *command)
{
	t_redirect	*aux;

	aux = command->red_out;
	while (aux)
	{
		open(aux->target, O_CREAT | O_RDONLY, 0777);
		aux = aux->next;
	}
}
