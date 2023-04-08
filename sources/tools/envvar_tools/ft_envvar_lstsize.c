/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_lstsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:25:35 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/07 18:50:31 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Returns the number of elements in the list.
int	ft_envvar_lstsize(t_env_vars *env_vars)
{
	int		size;

	size = 0;
	while (env_vars)
	{
		size++;
		env_vars = env_vars->next;
	}
	return (size);
}
