/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:15:52 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/01 15:47:18 by ridalgo-         ###   ########.fr       */
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

//Prints the environment variables
void	ft_print_env_vars(t_env_vars *head)
{
	t_env_vars	*aux;

	aux = head;
	while (aux)
	{
		printf("%s\n", aux->content);
		aux = aux->next;
	}
	return ;
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
