/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:22:02 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/30 02:28:20 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	refresh(t_list **plist)
{
	int		i;
	int		j;
	char	*buffer;
	t_list	*last;
	t_list	*new;

	buffer = malloc(BUFFER_SIZE + 1);
	new = malloc(sizeof(t_list));
	if (!new || !buffer)
	{
		free(buffer);
		return ;
	}
	last = ft_lstlast(*plist);
	i = 0;
	j = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	while (last->content[i] && last->content[++i])
		buffer[j++] = last->content[i];
	buffer[j] = 0;
	new->content = buffer;
	new->next = NULL;
	free_and_new(plist, new, &buffer);
}

int	newline_detector(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] && i < BUFFER_SIZE)
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

void	file_to_list(t_list **plist, int fd)
{
	int		len_read;
	char	*buffer;

	while (!newline_detector(*plist))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		len_read = read(fd, buffer, BUFFER_SIZE);
		if (len_read == 0)
		{
			free(buffer);
			return ;
		}
		buffer[len_read] = 0;
		add_cell(plist, buffer);
	}
}

char	*list_to_str(t_list *list)
{
	char	*res;
	int		length;

	if (!list)
		return (NULL);
	length = list_to_len(list);
	res = malloc(length + 1);
	if (!res)
		return (NULL);
	list_into_string(list, res);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	file_to_list(&list, fd);
	if (!list)
		return (NULL);
	str = list_to_str(list);
	refresh(&list);
	return (str);
}
