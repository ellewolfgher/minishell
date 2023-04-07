/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:42 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/06 18:10:36 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_env(t_env_vars *env_vars)
{
	while (env_vars)
	{
		printf("%s\n", env_vars->content);
		env_vars = env_vars->next;
	}
}
