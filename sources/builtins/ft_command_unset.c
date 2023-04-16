/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:51 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/15 20:56:01 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Remove the variable from the environment
void	ft_command_unset(t_data *ms, t_execute *cmd)
{
	char		*var_name;
	char		**args;
	int			i;

	i = 1;
	args = cmd->args;
	while (args[i])
	{
		var_name = args[i];
		ft_envvar_del(&ms->env_vars, var_name);
		i++;
	}
}
