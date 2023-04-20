/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:28:03 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/19 22:30:56 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_cd_home(t_data *ms)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (home_dir != NULL)
		chdir(home_dir);
	else
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		ms->exit_code = 1;
	}
}

static void	ft_cd_prev(t_data *ms)
{
	char	*prev_dir;
	char	*oldpwd;

	oldpwd = ft_envvar_get(ms->env_vars, "PWD");
	prev_dir = ft_envvar_get(ms->env_vars, "OLDPWD");
	if (prev_dir != NULL)
	{
		chdir(prev_dir);
		ft_putendl_fd(prev_dir, 1);
	}
	else
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		ms->exit_code = 1;
	}
	ft_envvar_update("OLDPWD", oldpwd, &ms->env_vars);
	ft_envvar_update("PWD", prev_dir, &ms->env_vars);
}

static void	ft_cd_path(t_data *ms, char *path)
{
	char	*oldpwd;

	oldpwd = getcwd(NULL, 0);
	if (chdir(path) == -1)
	{
		ft_free((void **)&oldpwd);
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		if (access(path, F_OK) != 0)
		{
			ft_putstr_fd(": No such file or directory\n", 2);
			ms->exit_code = 1;
		}
		else if (access(path, R_OK | X_OK) != 0)
		{
			ft_putstr_fd(": Permission denied\n", 2);
			ms->exit_code = 1;
		}
	}
	ft_update_path(ms, oldpwd);
	ms->exit_code = 0;
}

static void	handle_cd_arg(t_data *ms, t_execute *cmd)
{
	char	*arg;

	arg = cmd->args[1];
	if ((ft_strcmp(arg, "OLDPWD") == 0) || (ft_strcmp(arg, "-") == 0))
		ft_cd_prev(ms);
	else
	{
		if (ft_isdir(arg))
			ft_cd_path(ms, arg);
		else
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			ms->exit_code = 1;
		}
	}
}

void	ft_command_cd(t_data *ms, t_execute *cmd)
{
	char	*path;

	path = cmd->args[1];
	if ((path) && ft_args_len(cmd->args) > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		ms->exit_code = 1;
	}
	else if (!path || ft_strcmp(path, "~") == 0)
		ft_cd_home(ms);
	else if (path)
		handle_cd_arg(ms, cmd);
	ft_free((void **)&cmd->args);
}
