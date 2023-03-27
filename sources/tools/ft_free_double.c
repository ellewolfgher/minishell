/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:05:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 17:09:09 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_free_double(t_data *ms)
{
	int	index;

	index = 0;
	if (!ms->split)
		return (NULL);
	while (ms->split[index])
	{
		ms->split[index] = ft_free(ms->split[index]);
		index++;
	}
	ms->split = ft_free(ms->split);
	return (NULL);
}
