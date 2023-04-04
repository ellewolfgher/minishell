/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvars_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:23:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 16:58:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Gets all eviromental variables and saves them at ms->env_vars;
int	ft_envvars_init(t_data *ms, char **envp)
{
	int			index;

	index = 0;
	ms->env_vars = ft_envvar_new(envp[index]);
	index++;
	while (envp[index])
	{
		ft_envvar_back(&ms->env_vars, ft_envvar_new(envp[index]));
		index++;
	}
	return (0);
}
