/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:41:13 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/01 17:19:33 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "../../includes/minishell.h"

void	command_echo(char *args[])
{
	int	skip_newline;
	int	i;

	skip_newline = 0;
	i = 1;
	while (args[i] != NULL)
	{
		if (strcmp(args[i], "-n") == 0)
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
	while (args[i] != NULL)
	{
		printf("%s", args[i++]);
		if (args[i] != NULL)
			printf(" ");
	}
}
*/