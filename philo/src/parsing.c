/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:29 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:39:30 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **av)
{
	int			i;
	long int	nb;

	i = 1;
	nb = 0;
	while (av[i])
	{
		nb = ft_long_atoi(av[i]);
		if (!is_number(av[i]) || nb > 2147483647 || (i == 1 && nb > 200)
			|| nb == 0)
		{
			printf("not a valid number");
			exit(1);
		}
		i++;
	}
}
