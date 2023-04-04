/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:35:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 16:37:29 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Frees a single environment variable
void	ft_free_var(t_env_vars **node)
{
	ft_free((void **)&((*node)->content));
	ft_free((void **)&(*node));
}
