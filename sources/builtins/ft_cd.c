/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:28:03 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 14:58:46 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_cd(char **tokens)
{
	char	*home_dir;

	if (tokens[1] != NULL)
	{
		if (chdir(tokens[1]) == -1)
			printf("cd: %s: %s\n", tokens[1], strerror(errno));
	}
	else
	{
		home_dir = getenv("HOME");
		if (home_dir != NULL)
			chdir(home_dir);
	}
}
