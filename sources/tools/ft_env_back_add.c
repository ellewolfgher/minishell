/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_back_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:34 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/30 12:30:02 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env_back_add(t_env_var **env_vars, t_env_var *new)
{
	t_env_var	*last;

	if (!*env_vars)
	{
		*env_vars = new;
		return ;
	}
	last = *env_vars;
	while (last->next)
		last = last->next;
	last->next = new;
}
