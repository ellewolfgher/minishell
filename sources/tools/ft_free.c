/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:58:57 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 17:38:07 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Frees the memory cleanly
void	*ft_free(void *content)
{
	if (content != NULL)
	{
		free (content);
		content = NULL;
		return (NULL);
	}
	return (NULL);
}
