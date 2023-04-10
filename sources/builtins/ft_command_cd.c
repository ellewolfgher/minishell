/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:28:03 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/10 14:33:12 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_cd_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (home_dir != NULL)
		chdir(home_dir);
}

static void	ft_cd_prev(void)
{
	char	*prev_dir;

	prev_dir = getenv("OLDPWD");
	if (prev_dir != NULL)
	{
		ft_putendl_fd(prev_dir, 1);
		chdir(prev_dir);
	}
	else
		ft_putendl_fd("cd: OLDPWD not set", 2);
}

static void	ft_cd_path(char *path)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		if (errno == ENOENT)
			ft_putstr_fd("no such file or directory: ", 2);
		else if (errno == EACCES)
			ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
	}
}

static void	handle_cd_arg(t_data *ms)
{
	if (ft_strcmp(ms->tokens->next->value, "-") == 0)
		ft_cd_prev();
	else if (ft_isdigit(ms->tokens->next->value[0]))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(ms->tokens->next->value, 2);
		ft_putstr_fd("no such file or directory: ", 2);
		ms->exit_code = 1;
	}
	else
	{
		if (ft_isdir(ms->tokens->next->value))
			ft_cd_path(ms->tokens->next->value);
		else
		{
			ft_putstr_fd("cd: not a directory: ", 2);
			ft_putstr_fd(ms->tokens->next->value, 2);
			ft_putchar_fd('\n', 2);
			ms->exit_code = 255;
		}
	}
}

void	ft_command_cd(t_data *ms)
{
	size_t	argc;

	argc = ft_token_lst_size(ms->tokens);
	if (argc == 1)
		ft_cd_home();
	else if (argc > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		ms->exit_code = 1;
	}
	else
		handle_cd_arg(ms);
}
