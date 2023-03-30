/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:30:51 by ewolfghe          #+#    #+#             */
/*   Updated: 2023/03/16 15:51:47 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_command_unset(char **tokens)
{
	// Remove an environment variable
	char	**ep = NULL;
	char	**p; 

	// ep = __environ;
	while (*ep != NULL)
	{
		if (strncmp(tokens[1], *ep, strlen(tokens[1])) == 0 && (*ep)[strlen(tokens[1])] == '=')
		{
			// Shift the remaining elements down one position
			p = ep;
			while (*p != NULL)
			{
				*p = *(p + 1);
				p++;
			}
		}
		else
			ep++;
	}
}

/*
1- Define a linked list node structure that contains two fields: a string to store the variable name or message, and a pointer to the next node in the list. 
*/

/* struct node {
    char* data;
    struct node* next;
}; */

/* 
2 - Define a function to add a new node to the end of the linked list. This function takes a pointer to the head of the list, and the string to add. 
*/

/* void add_node(struct node** head, char* data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
} */


/* 
3 - Define functions to implement the export, env, unset, and echo commands, using the linked list to store and manipulate the environment variables and messages. 
*/

/* void export_command(char* argument, struct node** environment) {
    add_node(environment, argument);
    setenv(argument, "", 1);
}

void env_command(struct node* environment) {
    while (environment != NULL) {
        printf("%s\n", environment->data);
        environment = environment->next;
    }
}

void unset_command(char* argument, struct node** environment) {
    unsetenv(argument);
    struct node* current = *environment;
    struct node* previous = NULL;
    while (current != NULL) {
        if (strcmp(current->data, argument) == 0) {
            if (previous == NULL) {
                *environment = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->data);
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void echo_command(char* message, int suppress_newline) {
    if (suppress_newline) {
        printf("%s", message);
    } else {
        printf("%s\n", message);
    }
}
 */


/* 
4 - In your main program loop, read the user input and tokenize it into a command and argument(s) using the strtok function. Then, call the appropriate command function based on the command string.
*/

/* while (1) {
    char* input = readline("my-shell> ");
    char* command = strtok(input, " ");
    char* argument = strtok(NULL, " ");
    if (strcmp(command, "export") == 0) {
        export_command(argument, &environment);
    } else if (strcmp(command, "env") == 0) {
        env_command(environment);
    } else if (strcmp(command, "unset") == 0) {
        unset_command(argument, &environment);
    } else if (strcmp(command, "echo") == 0) {
        char* message = strtok(NULL, "");
        int suppress_newline = 0;
        if (message != NULL && strcmp(message, "-n") == 0) {
            message = strtok(NULL, "");
            suppress_newline = 1;
        }
        echo_command(message, suppress_newline);
    } else {
        // handle other commands
    }
    free(input);
} */
