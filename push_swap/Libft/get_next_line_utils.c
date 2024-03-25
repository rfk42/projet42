/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:40:41 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/21 11:14:41 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cherche un caractere saut de ligne dans la liste qui lui est donner */

int	newline(t_list *tmp)
{
	int		i;
	t_list	*current;

	i = 0;
	if (tmp == NULL)
		return (0);
	current = ft_lstlast(tmp);
	while (current->value[i])
	{
		if (current->value[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Renvoie un pointeur a la derniere position 
   contenant une valeur dans la liste */

t_list	*ft_lstlast(t_list *tmp)
{
	t_list	*current;

	current = tmp;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *tmp)
{
	int	i;
	int	len;

	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (tmp->value[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		tmp = tmp->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_tmp(t_list *tmp)
{
	t_list	*current;
	t_list	*next;

	current = tmp;
	while (current)
	{
		free(current->value);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlengnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
