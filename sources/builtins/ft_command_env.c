/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:42 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/13 20:28:39 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Print the environment variables
void	ft_command_env(t_data *ms)
{
	while (ms->env_vars)
	{
		printf("%s\n", ms->env_vars->content);
		ms->env_vars = ms->env_vars->next;
	}
}
