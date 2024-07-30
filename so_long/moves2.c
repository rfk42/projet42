/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:33:00 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/30 15:26:23 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

void	move_player_left(t_vars *vars, int i, int j, int *moved)
{
	char	left_cell;

	left_cell = vars->str[i][j - 1];
	if ((left_cell == '0' || left_cell == 'C') && vars->last_exit == 1)
	{
		vars->str[i][j - 1] = 'P';
		vars->str[i][j] = 'E';
		vars->last_exit = 0;
		*moved = 1;
	}
	else if (left_cell == '0' || left_cell == 'C')
	{
		vars->str[i][j] = '0';
		vars->str[i][j - 1] = 'P';
		*moved = 1;
	}
	else if (left_cell == 'E' && !check_exit(vars))
	{
		vars->str[i][j - 1] = 'P';
		vars->str[i][j] = '0';
		vars->last_exit = 1;
		*moved = 1;
	}
	else if (left_cell == 'E')
		mlx_loop_end(vars->mlx);
}

void	move_to_left(t_vars *vars)
{
	int	i;
	int	j;
	int	moved;

	moved = 0;
	find_player_position(vars, &i, &j);
	if (j > 0)
	{
		move_player_left(vars, i, j, &moved);
		if (moved)
		{
			vars->move_count++;
			ft_printf("Move count: %d\n", vars->move_count);
		}
	}
	print_map(vars);
}

void	move_player_right(t_vars *vars, int i, int j, int *moved)
{
	char	right_cell;

	right_cell = vars->str[i][j + 1];
	if ((right_cell == '0' || right_cell == 'C') && vars->last_exit == 1)
	{
		vars->str[i][j + 1] = 'P';
		vars->str[i][j] = 'E';
		vars->last_exit = 0;
		*moved = 1;
	}
	else if (right_cell == '0' || right_cell == 'C')
	{
		vars->str[i][j] = '0';
		vars->str[i][j + 1] = 'P';
		*moved = 1;
	}
	else if (right_cell == 'E' && !check_exit(vars))
	{
		vars->str[i][j + 1] = 'P';
		vars->str[i][j] = '0';
		vars->last_exit = 1;
		*moved = 1;
	}
	else if (right_cell == 'E')
		mlx_loop_end(vars->mlx);
}

void	move_to_right(t_vars *vars)
{
	int	i;
	int	j;
	int	moved;

	moved = 0;
	find_player_position(vars, &i, &j);
	if (vars->str[i][j + 1] != '\0')
	{
		move_player_right(vars, i, j, &moved);
		if (moved)
		{
			vars->move_count++;
			ft_printf("Move count: %d\n", vars->move_count);
		}
	}
	print_map(vars);
}
