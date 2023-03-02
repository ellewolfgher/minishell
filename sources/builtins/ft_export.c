/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 14:59:29 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_export(void)
{
	// Print all environment variables
	extern char	**environ;
	char		**env;

	env = environ;
	while (*env != NULL)
		printf("%s\n", *env++);
}
