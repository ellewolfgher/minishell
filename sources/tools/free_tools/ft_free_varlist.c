/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_varlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:36:40 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 16:37:17 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Frees a list of environment variables
void	ft_free_varlist(t_env_vars **head)
{
	t_env_vars *temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		ft_free_var(&temp);
	}
}
