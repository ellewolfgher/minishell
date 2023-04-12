/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 17:49:25 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Counts the number of arguments in the given token list.
Returns the count of arguments.

Example:
If the token list represents the command "program arg1 arg2", the function
returns 3 (1 for the command and 2 for the arguments).
*/
static int	ft_how_many_args(t_tokens *aux)
{
	t_tokens	*other;
	int			count;

	other = aux;
	count = 0;
	if (other && (other->type == COMTOKEN || other->type == BITOKEN))
	{
		count++;
		other = other->next;
	}
	while (other && other->type == WORDTOKEN)
	{
		count++;
		other = other->next;
	}
	return (count);
}

/*
Searches and sets the arguments for the command from the given token list.
Returns a dynamically allocated string matrix containing the arguments.

Example:
If the token list represents the command "program arg1 arg2", the resulting
string matrix will be ["program", "arg1", "arg2", NULL].
*/
char	**ft_searchset_arguments(t_data *ms)
{
	t_tokens	*aux;
	char		**matrix;
	int			count;
	int			index;

	count = 0;
	index = 0;
	aux = ft_tokens_iterate(ms);
	while (aux && (aux->type != COMTOKEN && aux->type != BITOKEN))
	{
		aux = aux->next;
		if (aux && aux->type == OPTOKEN)
			return (NULL);
	}
	if (!aux)
		return (NULL);
	count = ft_how_many_args(aux);
	matrix = ft_calloc(count + 1, sizeof(char *));
	while (index < count)
	{
		matrix[index] = ft_strdup(aux->value);
		aux = aux->next;
		index++;
	}
	return (matrix);
}
