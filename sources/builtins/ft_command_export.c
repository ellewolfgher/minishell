/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/16 15:37:59 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	ft_command_export(void)
// {
// 	// Print all environment variables
// 	extern char	**__environ;
// 	char		**env;

// 	env = __environ;
// 	while (*env != NULL)
// 		printf("%s\n", *env++);
// }
void	ft_command_export(void)
{
	extern char	**environ;
	char		*env_var;
	int			i;

	i = 0;
	env_var = getenv(environ[i]);
	while (env_var)
	{
		printf("%s\n", env_var);
		i++;
		env_var = getenv(environ[i]);
	}
}
