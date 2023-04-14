/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:15:09 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 18:15:45 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	n = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize <= dest_size)
		return (dstsize + src_size);
	while (dst[n] != 0)
		n++;
	while ((dest_size + i) < (dstsize - 1) && src[i] != 0)
	{
		dst[n] = src[i];
		n++;
		i++;
	}
	dst[n] = '\0';
	return (dest_size + src_size);
}
