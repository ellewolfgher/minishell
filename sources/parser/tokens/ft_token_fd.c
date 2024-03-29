/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:35:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/20 15:36:37 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if the previous token is a redirect, if it is, it is a file descriptor
int	ft_token_fd(t_tokens *aux)
{
	if (aux->prev && aux->prev->type == REDTOKEN)
		return (1);
	return (0);
}
