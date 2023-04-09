/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_envvars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:29:57 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:03:15 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Counts the number of environment variables
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

//Fills the vector with the environment variables
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

//Creates a vector of environment variables
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
