/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:51:31 by rhamini           #+#    #+#             */
/*   Updated: 2024/06/17 14:54:32 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

char	**call_parsing(char **av)
{
	int		len;
	char	**file;
	char	**copy_file;
	t_pos	pos;

	len = call_parsing_in_parsing(av[1]);
	if (len == 0)
		return (NULL);
	file = malloc(sizeof(char *) * (len + 1));
	if (!file)
		return (NULL);
	file[len] = NULL;
	field_string(file, av[1], len);
	if (!is_closed(file, len) || !find_textures(file, len)
		|| !rigth_textures(file, len))
		return (free_strings(file), NULL);
	pos = get_pos(file, len);
	copy_file = tab_dup(file, len);
	if (!copy_file)
		return (free_strings(file), NULL);
	find_path(copy_file, pos.ligne, pos.colonne);
	if (!c_est_pas_du_caca(copy_file, len))
		return (free_strings(copy_file), free_strings(file), NULL);
	free_strings(copy_file);
	return (file);
}

int	call_parsing_in_parsing(char *av)
{
	int	len;

	if (!check_file_format(av))
		return (0);
	len = how_much_lines(av);
	if (len == 0)
		return (0);
	if (!lines_length(len, av))
		return (0);
	return (len);
}

int	c_est_pas_du_caca(char **str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				return (0);
			if (str[i][j] == 'E' && !valid_exit(str, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_exit(char **str, int i, int j)
{
	return (str[i - 1][j] == 'V' || str[i + 1][j] == 'V' || str[i][j - 1] == 'V'
		|| str[i][j + 1] == 'V');
}
