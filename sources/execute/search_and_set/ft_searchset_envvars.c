/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_envvars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:29:57 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:05:10 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Counts the number of environment variables in the given list.
Returns the count of environment variables.

Example:
If the environment variable list contains "PATH=/usr/bin", "USER=username",
the function returns 2.
*/
static int	ft_count_env_vars(t_env_vars *head)
{
	t_env_vars	*aux;
	int			count;

	aux = head;
	count = 0;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	return (count);
}

/*
Fills the given string array with the environment variables from the list.
The size of the array should be at least equal to the number of environment
variables plus one for the NULL terminator.

Example:
If the environment variable list contains "PATH=/usr/bin", "USER=username",
and ret is a string array of size 3, the resulting array will be
["PATH=/usr/bin", "USER=username", NULL].
*/
static void	ft_fill_envvars(char **ret, t_env_vars *head, int top)
{
	int	index;

	index = 0;
	while (head && index < top - 1)
	{
		ret[index] = ft_strdup(head->content);
		index++;
		head = head->next;
	}
}

/*
Searches and sets the environment variables for the command from the given
environment variable list.
Returns a dynamically allocated string array containing the environment
variables.

Example:
If the environment variable list contains "PATH=/usr/bin", "USER=username",
the resulting string array will be ["PATH=/usr/bin", "USER=username", NULL].
*/
char	**ft_searchset_envvars(t_env_vars *head)
{
	t_env_vars	*aux;
	int			count;
	char		**list;

	aux = head;
	count = ft_count_env_vars(aux);
	if (!count)
		return (0);
	list = ft_calloc(count, sizeof(*list));
	ft_fill_envvars(list, aux, count);
	return (list);
}
