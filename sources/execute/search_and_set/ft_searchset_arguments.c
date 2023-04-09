/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_arguments.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:51:21 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:02:58 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Counts the number of consecutive WORDTOKENS in the command block
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

//Searches for the arguments in the command block and returns a vector with them
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
