/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_exit_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:10:44 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/02 00:24:31 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Updates the current token value by replacing the exit code 
//placeholder $? with the actual exit code.
//Allocates memory for the final token value.
static char	*ft_update_exit_code(char *str, char *exit_code, char *var_head)
{
	char	*start;
	char	*updated;

	start = ft_strjoin(str, exit_code);
	updated = ft_strjoin(start, var_head + 2);
	free(start);
	return (updated);
}

//Finds the first occurrence of the exit code placeholder $? in a string.
static char	*ft_find_exit_code(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1] == '?')
			return (str);
		str++;
	}
	return (NULL);
}

//Expands the exit code placeholder in the token list.
//Still needs to pass norminette.
void	ft_expand_exit_code(t_data *ms)
{
	char		*aux;
	char		*exit_str;
	char		*temporary;
	t_tokens	*head;

	head = ms->tokens;
	while (head)
	{
		if (head->value[0] == '\'')
		{
			head = head->next;
			continue ;
		}
		aux = ft_find_exit_code(head->value);
		if (aux)
		{
			*aux = '\0';
			exit_str = ft_itoa(ms->exit_code);
			temporary = head->value;
			head->value = ft_update_exit_code(head->value, exit_str, aux);
			ft_free((void **)&exit_str);
			ft_free((void **)&temporary);
		}
		else
			head = head->next;
	}
}
