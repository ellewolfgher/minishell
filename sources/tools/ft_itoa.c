/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:54:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 16:55:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_exceptions(int n)
{
	char	*max;
	char	*ret;

	max = "-2147483648";
	if (n == 0)
	{
		ret = ft_calloc(2, sizeof(char));
		ret[0] = '0';
		return (ret);
	}
	else
	{
		ret = ft_strdup(max);
		return (ret);
	}
}

//Transforms an integer into a string
//allocates memory for the string
char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0 || n == -2147483648)
	{
		str = ft_exceptions(n);
		return (str);
	}
	else
		len = ft_get_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
