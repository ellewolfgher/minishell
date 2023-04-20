/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:59:01 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/19 23:27:16 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Counts the number of input redirections in the given token list.
Returns the count of input redirections.

Example:
If the token list represents the command "cat < input.txt", the function
returns 1.
*/
static int	ft_count_inputs(t_tokens *aux)
{
	t_tokens	*other;
	int			count;

	count = 0;
	other = aux;
	if (other && other->type == OPTOKEN)
		other = other->next;
	while (other && other->type != OPTOKEN)
	{
		if (other->type == REDTOKEN)
		{
			if (!ft_strcmp("<", other->value))
				count++;
			else if (!ft_strcmp("<<", other->value))
				count++;
		}
		other = other->next;
	}
	return (count);
}

/*
Searches and sets the input redirections for the command from the given token
list.
Returns a dynamically allocated redirection list containing the input
redirections.

Example:
If the token list represents the command "cat < input.txt", the function
returns a redirection list of size 1, with a single redirection of type INFILE
and target "input.txt".
*/
static t_tokens	*ft_last_path(t_tokens *tokens)
{
	t_tokens *last;
	t_tokens *current;

	last = tokens;
	current = tokens;
	while (current)
	{
		if (current->next && ft_is_file(current->next->value))
			last = current->next;
		current = current->next;
	}
	return last;
}

/*
Fills the given redirection list with the input redirections from the token list.

Example:
If the token list represents the command "cat < input.txt", and this is a
redirection list of size 1, the resulting list will contain a single
redirection with type INFILE and target "input.txt".
*/
static void	ft_fill_inlist(t_redirect *this, t_tokens *tokens)
{
	t_tokens	*last;

	if (tokens && tokens->type == OPTOKEN)
		tokens = tokens->next;
	while (tokens && this && tokens->type != OPTOKEN)
	{
		if (tokens->type == REDTOKEN)
		{
			if (!ft_strcmp("<", tokens->value))
			{
				last = ft_last_path(tokens->next);
				this->type = INFILE;
				this->target = ft_strdup(last->value);
				this = this->next;
			}
			if (!ft_strcmp("<<", tokens->value))
			{
				this->type = HEREDOC;
				this->target = ft_strdup(tokens->next->value);
				this = this->next;
			}
		}
		tokens = tokens->next;
	}
}

/*
Searches and sets the input redirections for the command from the given token
list.
Returns a dynamically allocated redirection list containing the input
redirections.

Example:
If the token list represents the command "cat < input.txt", the resulting
redirection list will contain a single redirection with type INFILE and
target "input.txt".
*/
t_redirect	*ft_searchset_input(t_data *ms)
{
	t_tokens		*aux;
	t_redirect		*self;
	int				count;

	aux = ft_tokens_iterate(ms);
	count = ft_count_inputs(aux);
	self = ft_redirect_list(count);
	if (self)
		ft_fill_inlist(self, aux);
	return (self);
}
