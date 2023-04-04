/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_varlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 19:17:06 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Frees a list of environment variables
void	ft_free_varlist(t_env_vars **head)
{
	t_env_vars	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		ft_free_var(&temp);
	}
}
