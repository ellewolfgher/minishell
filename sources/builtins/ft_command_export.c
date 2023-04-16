/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/15 20:51:26 by ewolfghe         ###   ########.fr       */
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

void	ft_command_export(t_data *ms, t_execute *cmd)
{
	char		**split;
	int			i;

	i = 1;
	if (!cmd->args[1])
		return (ft_print_export(ms->env_vars));
	while (cmd->args[i])
	{	
		if (ft_strcmp(&cmd->args[i][0], "=") == 0)
			return (ft_print_error(ms, cmd->args[i]));
		split = ft_split(cmd->args[i], '=');
		if (!ft_is_valid_name(split[0]) || !split)
		{
			ft_print_error(ms, split[0]);
			ft_free_matrix((void ***)&split);
			i++;
			return ;
		}
		if (!split[1])
			ft_envvar_update(split[0], "", &ms->env_vars);
		else
			ft_envvar_update(split[0], split[1], &ms->env_vars);
		ft_free_matrix((void ***)&split);
		i++;
	}
}
