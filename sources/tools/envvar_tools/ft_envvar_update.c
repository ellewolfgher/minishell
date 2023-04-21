/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:39:35 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/20 22:36:40 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

// Finds and returns the envvar node with the specified name.
static t_env_vars	*ft_envvar_find(char *name, t_env_vars *env_vars)
{
	t_env_vars	*current;

	current = env_vars;
	while (current != NULL)
	{
		if (ft_strncmp(current->content, name, ft_strlen(name)) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}

// Replaces the value of the envvar with the specified name.
static void	ft_envvar_replace(char *name, char *value, t_env_vars **env_vars)
{
	t_env_vars	*node;
	char		*new_content;
	char		*equal_val;

	node = ft_envvar_find(name, *env_vars);
	if (ft_strcmp(value, "") == 0 || !value)
		new_content = ft_strdup(name);
	else
	{
		equal_val = ft_strjoin("=", value);
		new_content = ft_strjoin(name, equal_val);
		ft_free((void **)&equal_val);
	}
	if (node)
	{
		ft_free((void **)&node->content);
		node->content = new_content;
	}
	else
		ft_envvar_back(env_vars, ft_envvar_new(new_content));
}

// Updates the value of the envvar with the specified name.
void	ft_envvar_update(char *name, char *value, t_env_vars **env_vars)
{
	char		*var_str;
	char		*join_new;
	t_env_vars	*var;

	if (!name || !value)
		return ;
	if (ft_strcmp(value, "") != 0)
		var_str = ft_strjoin(name, "=");
	else
		var_str = ft_strdup(name);
	if (!var_str)
		return ;
	var = ft_envvar_find(name, *env_vars);
	if (var)
		ft_envvar_replace(name, value, env_vars);
	else
	{
		join_new = ft_strjoin(var_str, value);
		ft_envvar_back(env_vars, ft_envvar_new(join_new));
		ft_free((void **)&join_new);
	}
	ft_free((void **)&var_str);
}
