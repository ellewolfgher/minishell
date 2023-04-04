/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:54:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:05:34 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Creates a new variable node t_env_vars.
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
