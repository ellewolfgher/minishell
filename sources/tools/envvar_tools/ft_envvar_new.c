/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:54:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/07 18:51:04 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Creates a new element inside the list.
t_env_vars	*ft_envvar_new(char *content)
{
	t_env_vars	*new;

	new = (t_env_vars *)ft_calloc(1, sizeof(t_env_vars));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}
