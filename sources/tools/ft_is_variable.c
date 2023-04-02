/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:29:16 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/02 00:30:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Checks if a character is a valid variable name character, 
//which can be an alphanumeric character or an underscore.
int	ft_is_variable(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}
