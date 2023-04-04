/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_back_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:34 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 09:01:35 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_env_back_add(t_env_vars **env_vars, t_env_vars *new)
{
	t_env_vars	*last;

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
