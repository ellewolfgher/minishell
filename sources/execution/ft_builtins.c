/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:20:13 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/02 13:37:21 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	command_cd(char **tokens)
{
	// Change directory to the specified path, or to the home directory if no path is specified
	if (tokens[1] != NULL)
	{
		if (chdir(tokens[1]) == -1)
			printf("cd: %s: %s\n", tokens[1], strerror(errno));
	}
	else
	{
		char *home_dir = getenv("HOME");
		if (home_dir != NULL)
		{
			chdir(home_dir);
		}
	}
}

void	command_pwd(void)
{
	// Print the current working directory
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		printf("pwd: error getting current working directory\n");
	}
}

// void	command_export()
// {
// 	// Print all environment variables
//     extern char **environ;
//     char **env = environ;
//     while (*env != NULL)
//         printf("%s\n", *env++);
// }

// void	command_unset(char *args[1])
// {
// 	// Remove an environment variable
// 	char **ep = environ;
// 	while (*ep != NULL)
// 	{
// 		if (strncmp(var_name, *ep, strlen(var_name)) == 0 && (*ep)[strlen(var_name)] == '=')
// 		{
// 			// Shift the remaining elements down one position
// 			char **p = ep;
// 			while (*p != NULL)
// 			{
// 				*p = *(p + 1);
// 				p++;
// 			}
// 		}
// 		else
// 			ep++;
// 	}
// }

// void	command_env(char *args[])
// {
// 	// Print the value of an environment variable
// 	if (args[1] == NULL)
// 	{
//         // Print all environment variables
// 		extern char **environ; //global var that i need to fix
// 		char **env = environ;
// 		while (*env != NULL)
// 			printf("%s\n", *env++);
// 	}
// 	else
//     {
// 		// Print the value of a specific environment variable
//         char *value = getenv(args[1]);
//         if (value == NULL)
// 			printf("env: %s: No such file or directory\n", args[1]);
// 		else
// 			printf("%s\n", value);
// 	}
// }
