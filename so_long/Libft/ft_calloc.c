/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:42:38 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/20 00:01:43 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int				t;
	unsigned char	*allocmem;

	allocmem = 0;
	t = (nmemb * size);
	if (size && t / size != nmemb)
		return (NULL);
	allocmem = malloc(t);
	if (!allocmem)
		return (NULL);
	ft_bzero(allocmem, t);
	return ((void *)allocmem);
}
