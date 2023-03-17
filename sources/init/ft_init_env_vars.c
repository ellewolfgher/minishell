/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env_vars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:23:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/16 17:40:15 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Gets all eviromental variables and saves them at ms->env_vars;
int	ft_init_env_vars(t_data *ms, char **envp)
{
	int			index;
	t_env_vars	*temp;

	index = 0;
	ms->env_vars = ft_calloc(1, sizeof(*ms->env_vars));
	temp = ms->env_vars;
	while (envp[index])
	{
		temp->content = ft_strdup(envp[index]);
		if (envp[index + 1])
			temp->next = ft_calloc(1, sizeof(*ms->env_vars));
		temp = temp->next;
		index++;
	}
	return (0);
}
