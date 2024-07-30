/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:35 by rhamini           #+#    #+#             */
/*   Updated: 2024/06/17 14:57:08 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	how_much_lines(char *map)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		i++;
		free(str);
	}
	close(fd);
	return (i);
}

int	check_file_format(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i])
		i++;
	i = i - 4;
	if (map_name[i] != '.')
		return (0);
	i++;
	if (map_name[i] != 'b')
		return (0);
	i++;
	if (map_name[i] != 'e')
		return (0);
	i++;
	if (map_name[i] != 'r')
		return (0);
	i++;
	return (1);
}

int	lines_length(int len, char *map)
{
	int		line_len;
	int		others_lengths;
	char	*str;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	line_len = ft_strlen(str);
	free(str);
	while (len-- > 2)
	{
		str = get_next_line(fd);
		others_lengths = ft_strlen(str);
		free(str);
		if (others_lengths != line_len)
			return (0);
	}
	str = get_next_line(fd);
	others_lengths = ft_strlen(str);
	(free(str), close(fd));
	if (others_lengths != line_len - 1)
		return (0);
	return (1);
}

void	field_string(char **file, char *map, int len)
{
	int		fd;
	char	*str;
	int		i;
	char	*new_line;

	i = 0;
	fd = open(map, O_RDONLY);
	while (i < len)
	{
		str = get_next_line(fd);
		new_line = ft_strchr(str, '\n');
		if (new_line)
			*new_line = '\0';
		file[i] = str;
		i++;
	}
}

int	is_closed(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		if (j == 0 || j == len - 1)
		{
			while (map[j][i])
			{
				if (map[j][i] != '1')
					return (0);
				i++;
			}
		}
		else if (j > 0 && j < len - 1)
		{
			if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
				return (0);
		}
		j++;
		i = 0;
	}
	return (1);
}
