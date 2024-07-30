/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:33:00 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/30 15:26:24 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

void	find_player_position(t_vars *vars, int *i, int *j)
{
	*i = 0;
	*j = 0;
	while (vars->str[*i][*j] != 'P' && vars->str[*i][*j] != '\0')
	{
		(*j)++;
		if (vars->str[*i][*j] == '\0')
		{
			(*j) = 0;
			(*i)++;
		}
	}
}

void	move_player_up(t_vars *vars, int i, int j, int *moved)
{
	char	above_cell;

	above_cell = vars->str[i - 1][j];
	if ((above_cell == '0' || above_cell == 'C') && vars->last_exit == 1)
	{
		vars->str[i - 1][j] = 'P';
		vars->str[i][j] = 'E';
		vars->last_exit = 0;
		*moved = 1;
	}
	else if (above_cell == '0' || above_cell == 'C')
	{
		vars->str[i][j] = '0';
		vars->str[i - 1][j] = 'P';
		*moved = 1;
	}
	else if (above_cell == 'E' && !check_exit(vars))
	{
		vars->str[i - 1][j] = 'P';
		vars->str[i][j] = '0';
		vars->last_exit = 1;
		*moved = 1;
	}
	else if (above_cell == 'E')
		mlx_loop_end(vars->mlx);
}

void	move_up(t_vars *vars)
{
	int	i;
	int	j;
	int	moved;

	moved = 0;
	find_player_position(vars, &i, &j);
	if (i > 0)
	{
		move_player_up(vars, i, j, &moved);
		if (moved)
		{
			vars->move_count++;
			ft_printf("Move count: %d\n", vars->move_count);
		}
	}
	print_map(vars);
}

void	move_player_down(t_vars *vars, int i, int j, int *moved)
{
	char	below_cell;

	below_cell = vars->str[i + 1][j];
	if ((below_cell == '0' || below_cell == 'C') && vars->last_exit == 1)
	{
		vars->str[i + 1][j] = 'P';
		vars->str[i][j] = 'E';
		vars->last_exit = 0;
		*moved = 1;
	}
	else if (below_cell == '0' || below_cell == 'C')
	{
		vars->str[i][j] = '0';
		vars->str[i + 1][j] = 'P';
		*moved = 1;
	}
	else if (below_cell == 'E' && !check_exit(vars))
	{
		vars->str[i + 1][j] = 'P';
		vars->str[i][j] = '0';
		vars->last_exit = 1;
		*moved = 1;
	}
	else if (below_cell == 'E')
		mlx_loop_end(vars->mlx);
}

void	move_down(t_vars *vars)
{
	int	i;
	int	j;
	int	moved;

	moved = 0;
	find_player_position(vars, &i, &j);
	if (vars->str[i + 1] != NULL)
	{
		move_player_down(vars, i, j, &moved);
		if (moved)
		{
			vars->move_count++;
			ft_printf("Move count: %d\n", vars->move_count);
		}
	}
	print_map(vars);
}
