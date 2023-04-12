/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/12 00:38:36 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_get(t_env_vars *env_vars, const char *name)
{
	char		**split;
	char		*key;
	char		*value;
	t_env_vars	*temp;

	if (!env_vars)
		return (NULL);
	temp = env_vars;
	while (temp)
	{
		if (temp->content == NULL)
			return (NULL);
		split = ft_split(temp->content, '=');
		key = split[0];
		if (ft_strcmp(key, name) == 0)
		{
			value = split[1];
			ft_free_matrix((void ***)&split);
			return (value);
		}
		ft_free_matrix((void ***)&split);
		temp = temp->next;
	}
	return (NULL);
}

//Create a new environment variable or update an existing one
void	ft_command_export(t_tokens *tokens, t_env_vars **envp)
{
	t_tokens	*curr_token;
	size_t		name_len;
	char		*env_value;
	char		*var_name;

	curr_token = tokens->next;
	while (curr_token)
	{
		if (curr_token->type == WORDTOKEN && ft_strchr(curr_token->value, '='))
		{
			name_len = ft_strchr(curr_token->value, '=') - curr_token->value;
			var_name = ft_substr(curr_token->value, 0, name_len);
			env_value = ft_get(*envp, var_name);
			if (env_value)
				ft_free((void **)&(env_value));
			else
				ft_envvar_back(envp, ft_envvar_new(curr_token->value));
			env_value = ft_get(*envp, var_name);
			env_value = ft_strdup(curr_token->value);
			ft_free((void **)&var_name);
		}
		curr_token = curr_token->next;
	}
}

/* static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

static int	ft_check_name(char *str)
{
	if (!str || !ft_isalpha(*str) || *str == '_')
		return (0);
	str++;
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		else
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		str++;
	}
	return (1);
}

void	ft_command_export(t_data *ms, t_tokens *tokens, t_env_vars **envp)
{
	t_tokens	*curr_token;
	size_t		name_len;
	char		*env_value;
	char		*var_name;

	curr_token = tokens->next;
	while (curr_token)
	{
		if (curr_token->type == WORDTOKEN && ft_strchr(curr_token->value, '='))
		{
			name_len = ft_strchr(curr_token->value, '=') - curr_token->value;
			var_name = ft_substr(curr_token->value, 0, name_len);
			env_value = ft_get(*envp, var_name);
			if (env_value)
				ft_free((void **)&(env_value));
			else if (ft_check_name(var_name) == 1 || \
					ft_check_name(curr_token->value) == 1)
			{
				ft_check_name(var_name);
				ms->exit_code = 1;
			}
			else
				ft_envvar_back(envp, ft_envvar_new(curr_token->value));
			env_value = ft_get(*envp, var_name);
			env_value = ft_strdup(curr_token->value);
			ft_free((void **)&var_name);
		}
		curr_token = curr_token->next;
	}
} */