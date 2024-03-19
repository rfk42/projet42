/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:34:49 by rhamini           #+#    #+#             */
/*   Updated: 2024/01/16 18:07:02 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printout(unsigned int nb)
{
	if (nb > 9)
		ft_printui(nb / 10);
	if (nb <= 9)
	{
		ft_printchar(nb + 48);
		return ;
	}
	ft_printchar((nb % 10) + 48);
}

int	ft_printui(unsigned int nb)
{
	unsigned int	i;

	printout(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
