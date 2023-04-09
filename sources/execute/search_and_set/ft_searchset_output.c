/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchset_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:12:38 by ridalgo-          #+#    #+#             */
/*   Updated: 2023/04/09 19:03:23 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

//Counts the consecutive outputs redirections in the command block
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

//Creates a list of output redirections
static void	ft_fill_outlist(t_redirect *self, t_tokens *tokens)
{
	if (tokens && tokens->type == OPTOKEN)
		tokens = tokens->next;
	while (tokens && self && tokens->type != OPTOKEN)
	{
		if (tokens->type == REDTOKEN)
		{
			if (!ft_strcmp(">", tokens->value))
			{
				self->type = OVERWRITE;
				self->target = ft_strdup(tokens->next->value);
				self = self->next;
			}
			if (!ft_strcmp(">>", tokens->value))
			{
				self->type = APPEND;
				self->target = ft_strdup(tokens->next->value);
				self = self->next;
			}
		}
		tokens = tokens->next;
	}
}

//Sets the output redirections list
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
