/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h> 

void	execute_command(char *command)
{
    // Tokenize the command string into arguments
    char	*args[100];
    char	*arg;
	int		num_args;

	arg = command;
	num_args = 0;
    while (*arg != '\0')
    {
        while (*arg == ' ' || *arg == '\t' || *arg == '\n')
        {
            *arg++ = '\0';
        }
        args[num_args++] = arg;
        while (*arg != '\0' && *arg != ' ' && *arg != '\t' && *arg != '\n')
        {
            arg++;
        }
    }
    args[num_args] = NULL;

    // Handle built-in commands
    if (strcmp(args[0], "cd") == 0)
    {
        // Change directory to the specified path, or to the home directory if no path is specified
        if (args[1] != NULL)
        {
            if (chdir(args[1]) == -1)
            {
                printf("cd: %s: %s\n", args[1], strerror(errno));
            }
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
    else if (strcmp(args[0], "pwd") == 0)
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
    else if (strcmp(args[0], "exit") == 0)
    {
        // Exit the shell
        exit(0);
    }
}*/

/* int main() {
    char *command;
    while ((command = readline("\033[1;32m$ \033[0m"))) 
    {
		if (strlen(command) > 0)
		{
			execute_command(command);
		}
        printf("You entered: %s\n", command);
        free(command);
    }
    return 0;
} */
