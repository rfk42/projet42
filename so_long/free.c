/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:36:36 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/30 15:27:22 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

void	free_lib(t_vars *vars)
{
	free_strings(vars->str);
	vars->str = NULL;
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free_images(vars);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	free_images(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (vars->imgs[i] != NULL)
		{
			if (vars->mlx && vars->imgs[i])
				mlx_destroy_image(vars->mlx, vars->imgs[i]);
			vars->imgs[i] = NULL;
		}
		i++;
	}
}

void	free_tab(char **av)
{
	int	i;

	i = 0;
	if (!av || !(*av))
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av - 1);
	return ;
}
