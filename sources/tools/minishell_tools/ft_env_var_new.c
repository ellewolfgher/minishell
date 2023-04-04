/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 11:58:24 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/04 09:01:40 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
