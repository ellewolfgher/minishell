/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:26:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/11 17:08:01 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
** Concatenates the command from a token into all possible paths from the
** environmental variable, returns the pointer to it.
*/
static char	**ft_concatenate_this(char *cmd_arg, char **all_paths)
{
	int		index[3];
	char	*aux;

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (all_paths[index[0]])
	{
		aux = malloc (sizeof (char) * (ft_strlen(cmd_arg)
					+ 2 + ft_strlen(all_paths[index[0]])));
		while (all_paths[index[0]][index[1]])
		{
			aux[index[1]] = all_paths[index[0]][index[1]];
			index[1]++;
		}
		aux[index[1]++] = '/';
		while (cmd_arg[index[2]])
			aux[index[1]++] = cmd_arg[index[2]++];
		aux[index[1]] = '\0';
		index[1] = 0;
		index[2] = 0;
		free(all_paths[index[0]]);
		all_paths[index[0]++] = aux;
	}
	return (all_paths);
}

/*
** Tests all paths to check wether the command is accessible
*/
static char	*ft_find_paths(char **eachpath)
{
	int	index;

	index = 0;
	while (eachpath[index])
	{
		if (!access(eachpath[index], F_OK))
		{
			if (!access(eachpath[index], X_OK))
				return (ft_strdup(eachpath[index]));
		}
		index++;
	}
	return (NULL);
}

/*
** returns the path of the sent command
*/
static char	*ft_path_from_token(char *value, t_env_vars *env_head)
{
	t_env_vars	*aux;
	char		**eachpath;
	char		*path;

	aux = env_head;
	if (!ft_strncmp(value, ".", 1))
		return (ft_strdup(value));
	if (value[0] == '\0')
		return (ft_strdup(value));
	while (aux && ft_strncmp(aux->content, "PATH=", 5))
		aux = aux->next;
	if (!aux)
		return (NULL);
	eachpath = ft_split(aux->content + 5, ':');
	eachpath = ft_concatenate_this(value, eachpath);
	path = ft_find_paths(eachpath);
	ft_free_matrix((void ***)&eachpath);
	return (path);
}

/*
** Checks if there's a command from index onwards.
** Creates a heap allocated string of given command or builtin, ready to be
** sent to execution.
*/
char	*ft_searchset_command(t_data *ms, t_execute *this)
{
	t_tokens	*aux;
	char		*path;

	path = NULL;
	aux = ft_tokens_iterate(ms);
	while (aux && (aux->type != COMTOKEN && aux->type != BITOKEN))
		aux = aux->next;
	if (!aux)
		return (NULL);
	if (aux->type == BITOKEN)
	{
		this->is_builtin = 1;
		return (ft_strdup(aux->value));
	}
	if (aux->type == COMTOKEN)
		path = ft_path_from_token(aux->value, ms->env_vars);
	if (!path)
	{
		this->error_to_print = ft_strjoin(aux->value, ": command not found\n");
		return (ft_strdup(aux->value));
	}
	return (path);
}
