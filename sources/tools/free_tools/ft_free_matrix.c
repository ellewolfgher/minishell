/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:05:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:01:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_matrix(void ***matrix)
{
	int	index;

	index = 0;
	if (!*matrix)
		return ;
	while ((*matrix)[index])
	{
		ft_free((void **)&((*matrix)[index]));
		(*matrix)[index] = NULL;
		index++;
	}
	ft_free((void **)matrix);
	*matrix = NULL;
	return ;
}
