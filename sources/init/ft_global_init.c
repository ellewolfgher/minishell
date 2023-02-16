/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:52:54 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:57:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_global_init(void)
{
	g_interactions = malloc(sizeof(t_interactions));
	if (g_interactions == NULL)
	{
		perror("Error: failed to allocate memory for g_interactions\n");
		exit(EXIT_FAILURE);
	}
	return ;
}
