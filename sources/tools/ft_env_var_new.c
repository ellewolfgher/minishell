/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:24 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/30 15:34:32 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_vars	*ft_env_var_new(char *content)
{
	t_env_vars	*new;

	new = (t_env_vars *)malloc(sizeof(t_env_vars));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
