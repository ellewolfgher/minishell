/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:26:11 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 20:11:44 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Takes a command argument and a list of directory paths and concatenates each
path with the command argument, separated by a path separator character '/'.
Returns a matrix of dynamically allocated strings containing the resulting
concatenated strings.

If command is set to "program", and paths is set to a matrix of two strings
["/usr/bin", "/usr/local/bin"].
The resulting concatenated strings will be:
"/usr/bin/program" and "/usr/local/bin/program".
*/
static char	**ft_cat_paths_to_command(char *command, char **paths)
{
	int		index[3];
	char	*aux;

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	while (paths[index[0]])
	{
		aux = ft_calloc(1, sizeof (char) * (ft_strlen(command)
					+ 2 + ft_strlen(paths[index[0]])));
		while (paths[index[0]][index[1]])
		{
			aux[index[1]] = paths[index[0]][index[1]];
			index[1]++;
		}
		aux[index[1]++] = '/';
		while (command[index[2]])
			aux[index[1]++] = command[index[2]++];
		aux[index[1]] = '\0';
		index[1] = 0;
		index[2] = 0;
		free(paths[index[0]]);
		paths[index[0]++] = aux;
	}
	return (paths);
}

/*
Checks in the environmental variables for the PATH variable and returns the
path to the command. If the value is a relative path, returns the value.
Uses the ft_cat_paths_to_command function to concatenate the command with
all possible paths from the PATH variable and the ft_find_paths function to
check whether the command is accessible.
Returns the path to the command or NULL if it doesn't exist

Example:
If value is "program", and the PATH variable contains "/usr/bin:/usr/local/bin",
the function returns "/usr/local/bin/program" if the program is accessible there.
*/
static char	*ft_path_from_token(char *value, t_env_vars *environvars)
{
	t_env_vars	*aux;
	char		**allpaths;
	char		*path;

	aux = environvars;
	if (!ft_strncmp(value, ".", 1))
		return (ft_strdup(value));
	if (value[0] == '\0')
		return (ft_strdup(value));
	while (aux && ft_strncmp(aux->content, "PATH=", 5))
		aux = aux->next;
	if (!aux)
		return (NULL);
	allpaths = ft_split(aux->content + 5, ':');
	allpaths = ft_cat_paths_to_command(value, allpaths);
	path = ft_test_access(allpaths);
	ft_free_matrix((void ***)&allpaths);
	return (path);
}

/*
Checks if the command is a builtin. If it does, returns the name of the
builtin. If it doesn't, returns the path of the command to be executed.
It also sets flags in the t_execute struct to indicate whether the command
is a builtin or not.

Example:
If the command is "cd", a builtin command, the function returns "cd".
If the command is "program", and the PATH variable contains
"/usr/bin:/usr/local/bin", the function returns "/usr/local/bin/program"
if the program is accessible there.
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
