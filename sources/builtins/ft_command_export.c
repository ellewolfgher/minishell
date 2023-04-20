/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/19 22:31:50 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

//Check if variable name is valid and function's name's size is due to norme
static int	ft_val(const char *str)
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
	ft_putstr_fd("minishell: export: ", 2);
	ft_putstr_fd(key, 2);
	ft_putendl_fd(": not a valid identifier", 2);
	ms->exit_code = 1;
}

static void	ft_err_update(char *split0, char *split1, char *arg, t_data *ms)
{
	if (!split1 && !ft_strchr(arg, '='))
		ft_envvar_update(arg, "", &ms->env_vars);
	else if (!split1)
		ft_envvar_update(arg, "", &ms->env_vars);
	else
		ft_envvar_update(split0, split1, &ms->env_vars);
}

void	ft_command_export(t_data *ms, t_execute *cmd)
{
	char		**split;
	char		*arg;
	int			i;

	i = 1;
	if (!cmd->args[1])
		return (ft_print_export(ms->env_vars));
	while (cmd->args[i])
	{	
		arg = cmd->args[i];
		split = ft_split(cmd->args[i], '=');
		if (!ft_val(split[0]) || !split || ft_strcmp(&arg[0], "=") == 0)
		{
			ft_print_error(ms, arg);
			ft_free_matrix((void ***)&split);
			i++;
			return ;
		}
		ft_err_update(split[0], split[1], arg, ms);
		if (split)
			ft_free_matrix((void ***)&split);
		i++;
	}
}
