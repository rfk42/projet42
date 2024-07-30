/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:53:31 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/30 15:26:25 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

void	free_strings(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

int	key_pressed(int key, t_vars *vars)
{
	if (key == 65307)
		close_window(vars);
	if (key == 'a')
		move_to_left(vars);
	if (key == 'w')
		move_up(vars);
	if (key == 's')
		move_down(vars);
	if (key == 'd')
		move_to_right(vars);
	return (0);
}

int	close_window(t_vars *vars)
{
	free_lib(vars);
	exit(0);
}

int	check_exit(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->str[i])
	{
		while (vars->str[i][j])
		{
			if (vars->str[i][j] == 'C')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
