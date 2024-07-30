/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:55:21 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/29 19:27:24 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

int	get_adress(t_vars *vars)
{
	int	w;
	int	h;

	vars->imgs[0] = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &w, &h);
	vars->imgs[1] = mlx_xpm_file_to_image(vars->mlx, "vide.xpm", &w, &h);
	vars->imgs[2] = mlx_xpm_file_to_image(vars->mlx, "item.xpm", &w, &h);
	vars->imgs[3] = mlx_xpm_file_to_image(vars->mlx, "player.xpm", &w, &h);
	vars->imgs[4] = mlx_xpm_file_to_image(vars->mlx, "exit.xpm", &w, &h);
	if (vars->imgs[0] == NULL)
		return (free_lib(vars), 1);
	if (vars->imgs[1] == NULL)
		return (free_lib(vars), 1);
	if (vars->imgs[2] == NULL)
		return (free_lib(vars), 1);
	if (vars->imgs[3] == NULL)
		return (free_lib(vars), 1);
	if (vars->imgs[4] == NULL)
		return (free_lib(vars), 1);
	return (0);
}

void	print_map(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->str[i])
	{
		j = 0;
		while (vars->str[i][j])
		{
			get_images(vars, j, i);
			j++;
		}
		i++;
	}
}

void	get_images(t_vars *vars, int j, int i)
{
	if (vars->str[i][j] == '1' && vars->imgs[0] != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[0], 32 * j, 32
			* i);
	if (vars->imgs[0] == NULL)
		free_lib(vars);
	if (vars->str[i][j] == '0' && vars->imgs[1] != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[1], 32 * j, 32
			* i);
	if (vars->imgs[1] == NULL)
		free_lib(vars);
	if (vars->str[i][j] == 'C' && vars->imgs[2] != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[2], 32 * j, 32
			* i);
	if (vars->imgs[2] == NULL)
		free_lib(vars);
	if (vars->str[i][j] == 'P' && vars->imgs[3] != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[3], 32 * j, 32
			* i);
	if (vars->imgs[3] == NULL)
		free_lib(vars);
	if (vars->str[i][j] == 'E' && vars->imgs[4] != NULL)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs[4], 32 * j, 32
			* i);
	if (vars->imgs[4] == NULL)
		free_lib(vars);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		len;
	int		heigth;	

	if (ac != 2)
		return (1);
	ft_bzero(&vars, sizeof(t_vars));
	vars.str = call_parsing(av);
	if (!vars.str)
		return (ft_putstr_fd("Error\n", 2), 1);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (ft_putstr_fd("Error mlx\n", 2), free_lib(&vars), 1);
	len = win_length(&vars);
	heigth = win_heigth(&vars);
	vars.win = mlx_new_window(vars.mlx, len * 32, heigth * 32, "Hello world!");
	if (!vars.win)
		return (ft_putstr_fd("Error mlx\n", 2), free_lib(&vars), 1);
	if (get_adress(&vars))
		return (1);
	print_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, key_pressed, &vars);
	mlx_hook(vars.win, 17, 0L, close_window, vars.mlx);
	mlx_loop(vars.mlx);
	free_lib(&vars);
}
