/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:50:07 by rhamini           #+#    #+#             */
/*   Updated: 2024/07/29 15:35:27 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

int	win_length(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (vars->str[i])
		while (vars->str[i][j])
			j++;
	return (j);
}

int	win_heigth(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->str[i])
	{
		while (vars->str[i][j])
			j++;
		j = 0;
		i++;
	}
	return (i);
}
