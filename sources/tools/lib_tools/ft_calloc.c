/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:46:53 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:01:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*block;
	size_t	i;

	block = malloc(num_elements * element_size);
	if (block == NULL)
		return (NULL);
	i = 0;
	while (i < num_elements * element_size)
	{
		((char *)block)[i] = 0;
		i++;
	}
	return (block);
}
