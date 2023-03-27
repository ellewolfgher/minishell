/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:15:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/27 16:52:14 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Prints the tokens
void	ft_print_tokens(t_tokens *tokens)
{
	int			i;
	t_tokens	*aux;

	i = 0;
	aux = tokens;
	while (aux)
	{
		printf("Token %d:%s\n", i, aux->value);
		aux = aux->next;
		i++;
	}
}

//Prints the split
void	ft_print_split(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf("Split %d:%s\n", i, tokens[i]);
		i++;
	}
}
