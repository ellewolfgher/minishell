/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:42:20 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:47 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Checks if the token is a builtin
int	ft_token_builtin(char *value)
{
	if (!ft_strcmp(value, "echo"))
		return (1);
	if (!ft_strcmp(value, "cd"))
		return (1);
	if (!ft_strcmp(value, "pwd"))
		return (1);
	if (!ft_strcmp(value, "export"))
		return (1);
	if (!ft_strcmp(value, "unset"))
		return (1);
	if (!ft_strcmp(value, "env"))
		return (1);
	if (!ft_strcmp(value, "exit"))
		return (1);
	return (0);
}
