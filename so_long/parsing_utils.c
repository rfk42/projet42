/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:29:41 by rhamini           #+#    #+#             */
/*   Updated: 2024/06/13 15:57:55 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

int	find_textures(char **str, int len)
{
	int	i;
	int	j;
	int	find;

	i = 0;
	j = 1;
	find = 0;
	while (j < len - 1)
	{
		while (str[j][i])
		{
			if (str[j][i] == 'P' || str[j][i] == 'E' || str[j][i] == 'C')
				find++;
			i++;
		}
		i = 0;
		j++;
	}
	if (find < 3)
		return (0);
	return (1);
}

int	rigth_textures(char **str, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < len - 1)
	{
		while (str[j][i])
		{
			if (str[j][i] != 'P' && str[j][i] != 'E' && str[j][i] != 'C'
				&& str[j][i] != '1' && str[j][i] != '0')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

char	**tab_dup(char **src, int len)
{
	int		i;
	char	**dest;

	i = 0;
	dest = malloc(sizeof(char *) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = NULL;
	while (i < len)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
}

t_pos	get_pos(char **str, int len)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.colonne = 0;
	pos.ligne = 0;
	while (i < len)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				pos.ligne = i;
				pos.colonne = j;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

void	find_path(char **str, int ligne, int colonne)
{
	if (str[ligne][colonne] == 'V' || str[ligne][colonne] == '1'
		|| str[ligne][colonne] == 'E')
		return ;
	str[ligne][colonne] = 'V';
	find_path(str, ligne - 1, colonne);
	find_path(str, ligne + 1, colonne);
	find_path(str, ligne, colonne - 1);
	find_path(str, ligne, colonne + 1);
}
