/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/13 19:31:01 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_export(t_env_vars *env_vars)
{
	while (env_vars)
	{
		printf("declare -x %s\n", env_vars->content);
		env_vars = env_vars->next;
	}
}

static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

static int	ft_is_valid_name(const char *str)
{
	if (!str || !*str || !ft_isalpha(*str))
		return (0);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (0);
		str++;
	}
	return (1);
}

static void	ft_print_error(t_data *ms, char *key)
{
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(key, 2);
	ft_putendl_fd(": not a valid identifier", 2);
	ms->exit_code = 1;
}

void	ft_command_export(t_data *ms)
{
	t_tokens	*temp;
	char		**split;

	temp = ms->tokens->next;
	if (!ms->tokens->next)
		return (ft_print_export(ms->env_vars));
	while (temp)
	{	
		if (ft_strcmp(&temp->value[0], "=") == 0)
			return (ft_print_error(ms, temp->value));
		split = ft_split(temp->value, '=');
		if (!ft_is_valid_name(split[0]) || !split)
		{
			ft_print_error(ms, split[0]);
			ft_free_matrix((void ***)&split);
			temp = temp->next;
			return ;
		}
		if (!split[1])
			ft_envvar_update(split[0], "", &ms->env_vars);
		else
			ft_envvar_update(split[0], split[1], &ms->env_vars);
		ft_free_matrix((void ***)&split);
		temp = temp->next;
	}
}
