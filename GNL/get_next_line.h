/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:29:55 by rhamini           #+#    #+#             */
/*   Updated: 2024/01/24 17:24:37 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstlast(t_list *tmp);
char	*get_next_line(int fd);
void	read_tmp(int fd, t_list **tmp, int *lu_ptr);
int		newline(t_list *tmp);
void	add_in_tmp(t_list **tmp, char *buff, int lu);
void	extract_line(t_list *tmp, char **line);
void	clean_tmp(t_list **tmp);
void	free_tmp(t_list *tmp);
void	generate_line(char **line, t_list *tmp);
int		ft_strlen(char *str);

#endif