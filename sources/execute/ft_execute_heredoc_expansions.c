/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_heredoc_expansions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:51:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/14 18:23:49 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Updates the string to replace $? with the exit code. Takes a string, the exit
code, and a pointer to the position of $? in the string as parameters. Returns
the updated string.

Example: if str is "echo Hello $? World", exit_code is "0", and head is
pointer_to_$?, the function returns "echo Hello 0 World".
*/
static char	*ft_update_exit(char *str, char *exit_code, char *head)
{
	char	*aux;
	char	*new;

	aux = ft_strjoin(str, exit_code);
	new = ft_strjoin(aux, head + 2);
	ft_free((void **)&aux);
	return (new);
}

/*
 Expands all occurrences of $? with the exit code. Takes a pointer to t_data
 struct containing the exit code and the original string with $? as parameters.
 Returns the updated string with all occurrences of $? replaced by the exit code

 Example: if ms->exit_code is 0 and str is "echo $? $?",
 the function returns "echo 0 0".
*/
static char	*ft_get_exit_code(t_data *ms, char *str)
{
	char		*head;
	char		*exit_str;
	char		*aux;

	while (1)
	{
		head = ft_find_exit_code(str);
		if (head)
		{
			*head = '\0';
			exit_str = ft_itoa(ms->exit_code);
			aux = str;
			str = ft_update_exit(str, exit_str, head);
			ft_free((void **)&exit_str);
			exit_str = NULL;
			ft_free((void **)&aux);
			aux = NULL;
		}
		else
			break ;
	}
	return (str);
}

/*
 Updates the string to replace a variable with its value. Takes the original
 string with the variable, the variable name to be replaced, a pointer to the
 position of the variable in the string, and a pointer to t_data struct
 containing environment variables as parameters. Returns the updated string with
 the variable replaced by its value.

 Example: if str is "echo $USER", name is "USER", head is pointer_to_$USER,
 and ms has the USER variable set to "john", the function returns "echo john".
*/
static char	*ft_heredoc_update_str(char *str, char *name,
				char *head, t_data *ms)
{
	char	*value;
	char	*part1;
	char	*final_str;
	void	*aux;

	aux = str;
	value = ft_get_value(name, ms->env_vars);
	if (!value)
		part1 = ft_strdup(str);
	else
		part1 = ft_strjoin(str, value);
	final_str = ft_strjoin(part1, head + 1 + ft_strlen(name));
	ft_free((void **)&value);
	ft_free((void **)&part1);
	ft_free((void **)&aux);
	return (final_str);
}

/*
 Handles all variable and exit code expansions in a string. Takes the original
 string with variables and exit codes, and a pointer to t_data struct containing
 environment variables and exit codes as parameters. Returns the updated string
 with all variables and exit codes expanded.

 Example: if ms has USER set to "john", exit_code set to 0, and str is
 "echo $USER $?", the function returns "echo john 0".
*/
char	*ft_execute_heredoc_expansions(char *str, t_data *ms)
{
	char	*head;
	char	*name;

	while (1)
	{
		head = ft_find_variable(str);
		if (head)
		{
			name = ft_get_name(head);
			*head = '\0';
			str = ft_heredoc_update_str(str, name, head, ms);
			ft_free((void **)&name);
		}
		else
			break ;
	}
	str = ft_get_exit_code(ms, str);
	return (str);
}
