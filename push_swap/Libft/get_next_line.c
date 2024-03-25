/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:35:46 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/21 11:14:52 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_list	*tmp = NULL;
	char			*line;
	int				lu;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	lu = 1;
	line = NULL;
	read_tmp(fd, &tmp, &lu);
	if (tmp == NULL)
		return (NULL);
	extract_line(tmp, &line);
	clean_tmp(&tmp);
	if (line[0] == '\0')
	{
		free_tmp(tmp);
		tmp = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

/* utilise read pour ajouter les caracteres dans notre tampon */

void	read_tmp(int fd, t_list **tmp, int *lu_ptr)
{
	char	*buff;

	while (!newline(*tmp) && *lu_ptr != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == NULL)
			return ;
		*lu_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if ((*tmp == NULL && *lu_ptr == 0) || *lu_ptr == -1)
		{
			free(buff);
			return ;
		}
		buff[*lu_ptr] = '\0';
		add_in_tmp(tmp, buff, *lu_ptr);
		free(buff);
	}
}

/* Ajoute le contenu de notre buff a la fin de notre tampon */

void	add_in_tmp(t_list **tmp, char *buff, int lu)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	i = 0;
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->value = malloc(sizeof(char) * (lu + 1));
	if (new_node->value == NULL)
		return ;
	while (buff[i] && i < lu)
	{
		new_node->value[i] = buff[i];
		i++;
	}
	new_node->value[i] = '\0';
	if (*tmp == NULL)
	{
		*tmp = new_node;
		return ;
	}
	last = ft_lstlast(*tmp);
	last->next = new_node;
}

/* Extrait tous les caractères du tampon et 
   les affiche sur une seule ligne, s'arrete 
   des qu'elle rencontre un '\n */

void	extract_line(t_list *tmp, char **line)
{
	int	i;
	int	j;

	if (tmp == NULL)
		return ;
	generate_line(line, tmp);
	if (*line == NULL)
		return ;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->value[i])
		{
			if (tmp->value[i] == '\n')
			{
				(*line)[j++] = tmp->value[i];
				break ;
			}
			(*line)[j++] = tmp->value[i++];
		}
		tmp = tmp->next;
	}
	(*line)[j] = '\0';
}

/* Une fois la ligne qui a été lue extraite on se
   debarasse des caracteres stocker dans notre tampon
   La fontion se debarasse uniquement des caractères qui
   ont deja été retourner par notre fonction gnl */

void	clean_tmp(t_list **tmp)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (tmp == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*tmp);
	i = 0;
	while (last->value[i] && last->value[i] != '\n')
		i++;
	if (last->value && last->value[i] == '\n')
		i++;
	clean_node->value = malloc(sizeof(char)
			* ((ft_strlengnl(last->value) - i) + 1));
	if (clean_node->value == NULL)
		return ;
	j = 0;
	while (last->value[i])
		clean_node->value[j++] = last->value[i++];
	clean_node->value[j] = '\0';
	free_tmp(*tmp);
	*tmp = clean_node;
}

/*#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}*/