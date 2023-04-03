/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:27:24 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/03 18:48:54 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Extracts the variable name from a string that starts with a $ symbol.
//Allocates memory for the variable name.
static char	*ft_extract_name(char	*var_head)
{
	size_t	lenght;

	lenght = 0;
	if (*var_head == '$')
		var_head++;
	while (var_head[lenght] && ft_is_variable(var_head[lenght]))
		lenght++;
	return (ft_substr(var_head, 0, lenght));
}

//Retrieves the value of a given variable name
//from an environment variable linked list.
//Allocates memory for the variable value.
static char	*ft_retrieve_value(char *name, t_env_vars *env)
{
	size_t	lenght;
	char	*str;
	char	*return_value;

	return_value = NULL;
	lenght = 0;
	while (env)
	{
		str = env->content;
		if (ft_match_variables(str, name))
		{
			while (*str != '=')
				str++;
			str++;
			while (str[lenght])
				lenght++;
			return_value = ft_substr(str, 0, lenght);
		}
		env = env->next;
	}
	return (return_value);
}

//Updates the current token value by replacing
//the variable name with its corresponding value.
//Allocates memory for the new token value.
static char	*ft_new_name(t_data *ms, char *var_name, char *var_head)
{
	char	*initial_value;
	char	*aux;
	char	*updated_value;
	void	*temporary;

	temporary = ms->tokens->value;
	initial_value = ft_retrieve_value(var_name, ms->env_vars);
	if (!initial_value)
		aux = ft_strdup(ms->tokens->value);
	else
		aux = ft_strjoin(ms->tokens->value, initial_value);
	updated_value = ft_strjoin(aux, var_head + 1 + ft_strlen(var_name));
	free(initial_value);
	free(aux);
	free(temporary);
	return (updated_value);
}

//If a variable is found in the token value,
//calls the update_token function to update the token value.
static void	ft_found_var(char *var_head, t_data *ms)
{
	char	*aux;

	aux = ft_extract_name(var_head);
	*var_head = '\0';
	ms->tokens->value = ft_new_name(ms, aux, var_head);
	ft_free((void **)&aux);
}

//Expands all the variables found in the token list.
void	ft_expand_variables(t_data *ms)
{
	char		*to_find;
	t_tokens	*head;

	head = ms->tokens;
	while (ms->tokens)
	{
		if (ms->tokens->value[0] == '\'')
		{
			ms->tokens = ms->tokens->next;
			continue ;
		}
		to_find = ft_find_variable(ms->tokens->value);
		if (to_find)
			ft_found_var(to_find, ms);
		else
			ms->tokens = ms->tokens->next;
	}
	ms->tokens = head;
}
