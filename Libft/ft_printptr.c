/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:06:28 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/21 10:32:15 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_printchar((n + '0'));
		else
			ft_printchar((n - 10 + 'a'));
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	final_len;

	final_len = 0;
	if (ptr == 0)
		final_len += write(1, "(nil)", 5);
	else
	{
		final_len += write(1, "0x", 2);
		final_len += ft_ptr_len(ptr);
		ft_put_ptr(ptr);
	}
	return (final_len);
}
