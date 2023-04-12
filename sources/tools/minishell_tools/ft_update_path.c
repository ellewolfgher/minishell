/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:40:38 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/12 13:41:49 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_update_path(t_data *ms, char *oldpwd)
{
	char	*pwd;
	char	*oldpwd_env;
	char	*pwd_env;
	char	cwd[PATH_MAX];

	pwd = getcwd(cwd, PATH_MAX - 1);
	oldpwd_env = ft_envvar_get(ms->env_vars, "OLDPWD");
	pwd_env = ft_envvar_get(ms->env_vars, "PWD");
	if (oldpwd_env)
		ft_envvar_update("OLDPWD", oldpwd, &ms->env_vars);
	if (pwd_env)
		ft_envvar_update("PWD", pwd, &ms->env_vars);
	ft_free((void **)&oldpwd);
}
