/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:42 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 14:59:52 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_env(char **tokens)
{
	// Print the value of an environment variable
	extern char	**environ; //extern var that i need to fix
	char		**env;
	char		*value;

	if (tokens[1] == NULL)
	{
		// Print all environment variables
		env = environ;
		while (*env != NULL)
			printf("%s\n", *env++);
	}
	else
	{
		// Print the value of a specific environment variable
		value = getenv(tokens[1]);
		if (value == NULL)
			printf("env: %s: No such file or directory\n", tokens[1]);
		else
			printf("%s\n", value);
	}
}
