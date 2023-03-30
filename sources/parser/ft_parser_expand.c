/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:56 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/03/30 18:36:08 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_variable(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int	vars_match(char *env_var, char *var_name)
{
	size_t		var_size;

	var_size = ft_strlen(var_name);
	if (!ft_strncmp(env_var, var_name, var_size)
		&& *(env_var + var_size) == '=')
		return (1);
	return (0);
}

char	*get_var_name(char	*var_head)
{
	size_t	len;

	len = 0;
	if (*var_head == '$')
		var_head++;
	while (var_head[len] && is_variable(var_head[len]))
		len++;
	return (ft_substr(var_head, 0, len));
}

char	*find_variable(char	*str)
{
	while (*str)
	{
		if (*str == '$' && is_variable(str[1]))
			return (str);
		str++;
	}
	return (NULL);
}

char	*get_var_value(char *name, t_env_vars *env)
{
	size_t	len;
	char	*str;
	char	*var_value;

	var_value = NULL;
	len = 0;
	while (env)
	{
		str = env->content;
		if (vars_match(str, name))
		{
			while (*str != '=')
				str++;
			str++;
			while (str[len])
				len++;
			var_value = ft_substr(str, 0, len);
		}
		env = env->next;
	}
	return (var_value);
}

char	*update_token(t_data *ms, char *var_name, char *var_head)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*temp;

	temp = ms->tokens->value;
	value = get_var_value(var_name, ms->env_vars);
	if (!value)
		part1 = ft_strdup(ms->tokens->value);
	else
		part1 = ft_strjoin(ms->tokens->value, value);
	final_str = ft_strjoin(part1, var_head + 1 + ft_strlen(var_name));
	free(value);
	free(part1);
	free(temp);
	return (final_str);
}

void	if_variable(char *var_head, t_data *ms)
{
	char	*var_name;

	var_name = get_var_name(var_head);
	*var_head = '\0';
	ms->tokens->value = update_token(ms, var_name, var_head);
	free(var_name);
}

void	expand_variables(t_data *ms)
{
	char		*var_head;
	t_tokens	*head;

	head = ms->tokens;
	while (ms->tokens)
	{
		if (ms->tokens->value[0] == '\'')
		{
			ms->tokens = ms->tokens->next;
			continue ;
		}
		var_head = find_variable(ms->tokens->value);
		if (var_head)
			if_variable(var_head, ms);
		else
			ms->tokens = ms->tokens->next;
	}
	ms->tokens = head;
}

char	*update_token_exit_code(char *str, char *exit_code, char *var_head)
{
	char	*part1;
	char	*final_str;

	part1 = ft_strjoin(str, exit_code);
	final_str = ft_strjoin(part1, var_head + 2);
	free(part1);
	return (final_str);
}

char	*find_exit_code(char *str)
{
	while (*str)
	{
		if (*str == '$' && str[1] == '?')
			return (str);
		str++;
	}
	return (NULL);
}

void	expand_exit_code(t_data *ms)
{
	char		*v_head;
	char		*exit_str;
	char		*temp;
	t_tokens	*head;

	head = ms->tokens;
	while (head)
	{
		if (head->value[0] == '\'')
		{
			head = head->next;
			continue ;
		}
		v_head = find_exit_code(head->value);
		if (v_head)
		{
			*v_head = '\0';
			exit_str = ft_itoa(ms->exit_code);
			temp = head->value;
			head->value = update_token_exit_code(head->value, exit_str, v_head);
			ft_free((void **)&exit_str);
			ft_free((void **)&temp);
		}
		else
			head = head->next;
	}
}

void	ft_parser_expand(t_data *ms)
{
	expand_exit_code(ms);
	expand_variables(ms);
}
