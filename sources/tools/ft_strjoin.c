/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:57:19 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 16:57:36 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	cat = (char *)ft_calloc(len, sizeof(char));
	if (!cat)
		return (NULL);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cat[i] = s2[j];
		j++;
		i++;
	}
	cat[i] = 0;
	return (cat);
}
