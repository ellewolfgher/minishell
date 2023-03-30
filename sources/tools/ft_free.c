/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:57 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 12:05:12 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Frees the memory cleanly
void	ft_free(void *pointer)
{
	if (!pointer)
		return ;
	free(pointer);
	pointer = NULL;
	return ;
}
