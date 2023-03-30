/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:42 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/16 15:44:40 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	ft_command_env(char **tokens)
// {
// 	// Print the value of an environment variable
// 	extern char	**__environ; //extern var that i need to fix
// 	char		**env;
// 	char		*value;

// 	if (tokens[1] == NULL)
// 	{
// 		// Print all environment variables
// 		env = __environ;
// 		while (*env != NULL)
// 			printf("%s\n", *env++);
// 	}
// 	else
// 	{
// 		// Print the value of a specific environment variable
// 		value = getenv(tokens[1]);
// 		if (value == NULL)
// 			printf("env: %s: No such file or directory\n", tokens[1]);
// 		else
// 			printf("%s\n", value);
// 	}
// }
void	ft_command_env(char **tokens)
{
	extern char	**environ;
	char		**env;
	char		*value;
	int			i;

	i = 0;
	if (tokens[1] == NULL)
	{
		env = environ;
		while (env[i])
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		value = getenv(tokens[1]);
		if (value == NULL)
			printf("env: %s: No such file or directory\n", tokens[1]);
		else
			printf("%s\n", value);
	}
}
