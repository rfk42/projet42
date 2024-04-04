/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:12:44 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/30 17:45:35 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (nbr * signe);
}
