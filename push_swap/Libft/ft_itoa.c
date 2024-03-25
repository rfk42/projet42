/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:26 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/20 15:14:37 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	countdown(int i)
{
	unsigned int	count;

	if (i <= 0)
		count = 1;
	else
		count = 0;
	while (i != 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	char			c;
	unsigned int	i;

	i = countdown(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		c = n % 10;
		if (n < 0)
			c = -c;
		str[--i] = (c + '0');
		n /= 10;
	}
	return (str);
}
