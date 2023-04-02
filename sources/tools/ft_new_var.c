/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:54:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/01 15:55:14 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_vars	*ft_new_var(char *content)
{
	t_env_vars	*new;

	new = (t_env_vars *)ft_calloc(1, sizeof(t_env_vars));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	new->next = NULL;
	return (new);
}
