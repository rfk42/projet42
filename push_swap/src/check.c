/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:56:20 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/17 03:12:45 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	support_long(char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		n = ft_atoi(av[i]);
		if (n < -2147483648 || n > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	is_nb(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] && (!(str[i] >= '0' && str[i] <= '9')))
		return (0);
	return (1);
}

int	check_nb(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!is_nb(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(int ac, char **av)
{
	if (ac < 2)
		return (ft_putstr(""), 1);
	if (!check_nb(av))
		return (ft_putstr("Error\nArgument invalide"), 1);
	if (!check_double(av))
		return (ft_putstr("Error\nDoublons"), 1);
	if (!support_long(av))
		return (ft_putstr("Error\nArgument trop grand"), 1);
	return (0);
}
