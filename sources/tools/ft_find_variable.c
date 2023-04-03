/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:32:35 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/02 00:32:48 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Finds the first occurrence of a variable in a string
//starting with a $ symbol and followed by a valid
//variable name character.
char	*ft_find_variable(char	*str)
{
	while (*str)
	{
		if (*str == '$' && ft_is_variable(str[1]))
			return (str);
		str++;
	}
	return (NULL);
}
