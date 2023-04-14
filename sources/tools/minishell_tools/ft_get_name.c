/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:03:46 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 18:03:56 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Extracts the variable name starting at the given position in the string. Takes a
pointer to the position of the variable in the string as a parameter. Returns
the extracted variable name without the initial '$' character.

Example: if head points to the position of "$VAR" in the string "echo $VAR",
the function returns "VAR".
*/
char	*ft_get_name(char *head)
{
	size_t	lenght;

	lenght = 0;
	if (*head == '$')
		head++;
	while (head[lenght] && ft_is_variable(head[lenght]))
		lenght++;
	return (ft_substr(head, 0, lenght));
}
