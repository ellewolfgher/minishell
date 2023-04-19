/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:39:55 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/18 22:42:02 by ewolfghe         ###   ########.fr       */
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
	ft_putstr_fd("export: ", 2);
	ft_putstr_fd(key, 2);
	ft_putendl_fd(": not a valid identifier", 2);
	ms->exit_code = 1;
}

void	ft_error_and_update(char *split0, char *split1, char *value, t_data *ms)
{
	if (!split1 && ft_strcmp(value, "=") != 0)
		ft_envvar_update(value, "", &ms->env_vars);
	else if (!split1)
		ft_envvar_update(value, "", &ms->env_vars);
	else
		ft_envvar_update(split0, split1, &ms->env_vars);
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
		split = ft_split(temp->value, '=');
		if (!ft_val(split[0]) || !split || ft_strcmp(&temp->value[0], "=") == 0)
		{
			ft_print_error(ms, temp->value);
			ft_free_matrix((void ***)&split);
			temp = temp->next;
			return ;
		}
		ft_error_and_update(split[0], split[1], temp->value, ms);
		if (split)
			ft_free_matrix((void ***)&split);
		temp = temp->next;
	}
}
