/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/04 15:01:54 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_export(void)
{
	// Print all environment variables
	extern char	**__environ;
	char		**env;

	env = __environ;
	while (*env != NULL)
		printf("%s\n", *env++);
}
