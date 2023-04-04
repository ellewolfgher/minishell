/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:02:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/04 09:04:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Copies a string to a new string (allocates memory)
char	*ft_strdup(const char *tobecopied)
{
	char	*newstring;
	int		i;

	if (!tobecopied)
		return (NULL);
	newstring = (char *) malloc(ft_strlen(tobecopied) + 1);
	if (!newstring)
		return (NULL);
	i = 0;
	while (tobecopied[i])
	{
		newstring[i] = tobecopied[i];
		i++;
	}
	newstring[i] = 0;
	return (newstring);
}
