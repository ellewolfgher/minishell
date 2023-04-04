/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:51 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 19:20:05 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_unset(char **tokens)
{
	char	**ep;
	char	**p;

	ep = NULL;
	while (*ep != NULL)
	{
		if (strncmp(tokens[1], *ep, strlen(tokens[1])) == 0 && \
					(*ep)[strlen(tokens[1])] == '=')
		{
			p = ep;
			while (*p != NULL)
			{
				*p = *(p + 1);
				p++;
			}
		}
		else
			ep++;
	}
}
