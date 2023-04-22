/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 21:30:35 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/04/21 21:07:12 by ewolfghe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/* static void	ft_lstclear_env_vars(t_env_vars **lst)
{
	t_env_vars	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_free((void **)&((*lst)->content));
		*lst = tmp;
	}
	*lst = NULL;
} */

static t_env_vars	*ft_lstnew_env_vars(char *content)
{
	t_env_vars	*new;

	new = (t_env_vars *)ft_calloc(1, sizeof(t_env_vars));
	if (!new)
		return (NULL);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		ft_free_varlist(&new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

static t_env_vars	*ft_lstcpy_env_vars(t_env_vars *lst)
{
	t_env_vars	*new;
	t_env_vars	*tmp;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew_env_vars(lst->content);
		if (!tmp)
		{
			ft_free_varlist(&new);
			return (NULL);
		}
		tmp->next = new;
		new = tmp;
		lst = lst->next;
	}
	return (new);
}

static void	ft_sort_env_vars(t_env_vars **env_vars)
{
	t_env_vars	*tmp1;
	t_env_vars	*tmp2;
	char		*temp;

	tmp1 = *env_vars;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (ft_strcmp(tmp1->content, tmp2->content) > 0)
			{
				temp = tmp1->content;
				tmp1->content = tmp2->content;
				tmp2->content = temp;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	ft_print_export(t_env_vars *env_vars)
{
	t_env_vars	*env_copy;
	char		*env_str;
	char		*var_value;

	env_copy = ft_lstcpy_env_vars(env_vars);
	if (!env_copy)
		return ;
	ft_sort_env_vars(&env_copy);
	while (env_copy)
	{
		env_str = ft_strdup(env_copy->content);
		if (!env_str)
			continue ;
		var_value = ft_strchr(env_str, '=');
		if (var_value)
		{
			*var_value = '\0';
			printf("declare -x %s=\"%s\"\n", env_str, var_value + 1);
		}
		else
			printf("declare -x %s\n", env_str);
		ft_free((void **)&env_str);
		env_copy = env_copy->next;
	}
	ft_free_varlist(&env_copy);
}
