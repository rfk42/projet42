/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:17:13 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/13 14:23:35 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(char *str)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const c)
{
	unsigned int	i;
	char			*s3;

	i = 0;
	if (s1 == 0)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i] = c;
	i++;
	s3[i] = '\0';
	free(s1);
	return (s3);
}

void	ft_putstr(char *s)
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

void	ft_putnbr(int nb)
{
	long	x;

	x = (long)nb;
	if (x < 0)
	{
		ft_putchar('-');
		x *= -1;
	}
	if (x > 9)
		ft_putnbr(x / 10);
	ft_putchar((x % 10) + '0');
}
