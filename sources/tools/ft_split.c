/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:30:13 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/30 12:30:14 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void		ft_alloc_strs(char **res, char *s, char c, size_t strs);

static size_t	ft_count_strs(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	strs;

	strs = ft_count_strs(s, c);
	res = (char **)malloc(sizeof(char *) * (strs + 1));
	if ((!s && s[0] == '\0') || !res)
		return (NULL);
	ft_alloc_strs(res, (char *)s, c, strs);
	res[strs] = NULL;
	return (res);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	strs;
	size_t	is_str;
	size_t	i;

	strs = 0;
	is_str = 1;
	i = 0;
	while (s != NULL && s[i])
	{
		if (s[i] != c && is_str)
		{
			is_str = 0;
			strs++;
		}
		else if (s[i] == c)
			is_str = 1;
		i++;
	}
	return (strs);
}

static void	ft_alloc_strs(char **res, char *s, char c, size_t strs)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < strs)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				end = i;
			i++;
		}
		res[j] = ft_substr(&s[start], 0, (end - start + 1));
		j++;
	}
}
