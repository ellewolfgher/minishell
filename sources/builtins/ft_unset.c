/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:51 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/04 15:01:27 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_unset(char **tokens)
{
	// Remove an environment variable
	char	**ep;
	char	**p; 

	ep = __environ;
	while (*ep != NULL)
	{
		if (strncmp(tokens[1], *ep, strlen(tokens[1])) == 0 && (*ep)[strlen(tokens[1])] == '=')
		{
			// Shift the remaining elements down one position
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
