/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_exit_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:53:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 16:53:43 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Finds the first occurrence of the exit code placeholder $? in a string.
char	*ft_find_exit_code(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1] == '?')
			return (str);
		str++;
	}
	return (NULL);
}
