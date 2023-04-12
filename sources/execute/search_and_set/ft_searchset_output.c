/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:12:38 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/12 18:02:50 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*
Counts the number of output redirections in the given token list.
Returns the count of output redirections.

Example:
If the token list represents the command "cat > output.txt", the function
returns 1.
*/
static int	ft_count_outputs(t_tokens *aux)
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
			if (!ft_strcmp(">", other->value))
				count++;
			else if (!ft_strcmp(">>", other->value))
				count++;
		}
		other = other->next;
	}
	return (count);
}

/*
Fills the given redirection list with the output redirections from the token
list.

Example:
If the token list represents the command "cat > output.txt", and this is a
redirection list of size 1, the resulting list will contain a single
redirection with type OVERWRITE and target "output.txt".
*/
static void	ft_fill_outlist(t_redirect *this, t_tokens *tokens)
{
	if (tokens && tokens->type == OPTOKEN)
		tokens = tokens->next;
	while (tokens && this && tokens->type != OPTOKEN)
	{
		if (tokens->type == REDTOKEN)
		{
			if (!ft_strcmp(">", tokens->value))
			{
				this->type = OVERWRITE;
				this->target = ft_strdup(tokens->next->value);
				this = this->next;
			}
			if (!ft_strcmp(">>", tokens->value))
			{
				this->type = APPEND;
				this->target = ft_strdup(tokens->next->value);
				this = this->next;
			}
		}
		tokens = tokens->next;
	}
}

/*
Searches and sets the output redirections for the command from the given token
list.
Returns a dynamically allocated redirection list containing the output
redirections.

Example:
If the token list represents the command "cat > output.txt", the resulting
redirection list will contain a single redirection with type OVERWRITE and
target "output.txt".
*/
t_redirect	*ft_searchset_output(t_data *ms)
{
	t_tokens		*aux;
	t_redirect		*self;
	int				count;

	aux = ft_tokens_iterate(ms);
	count = ft_count_outputs(aux);
	self = ft_redirect_list(count);
	if (self)
		ft_fill_outlist(self, aux);
	return (self);
}
