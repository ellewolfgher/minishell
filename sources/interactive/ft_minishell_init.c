/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:22:42 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/02/16 19:24:13 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	*ft_minishell_init(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("Error: failed to allocate memory for data\n");
		exit(EXIT_FAILURE);
	}
	g_interactions = malloc(sizeof(t_interactions));
	if (g_interactions == NULL)
	{
		perror("Error: failed to allocate memory for g_interactions\n");
		exit(EXIT_FAILURE);
	}
	ft_initiate_interactive_signals(data);
	return (data);
}
