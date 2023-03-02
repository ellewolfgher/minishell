/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:45 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 14:55:31 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_echo(char **tokens)
{
	int	skip_newline;
	int	i;

	skip_newline = 0;
	i = 1;
	while (tokens[i] != NULL)
	{
		if (strcmp(tokens[i], "-n") == 0)
		{
			skip_newline = 1;
			break ;
		}
		i++;
	}
	// Print the remaining arguments without a trailing newline if "-n" option is present
	if (skip_newline)
		i = 2;
	else
		i = 1;
	while (tokens[i] != NULL)
	{
		printf("%s", tokens[i++]);
		if (tokens[i] != NULL)
			printf(" ");
	}
}
