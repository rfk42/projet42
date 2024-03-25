/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:31:28 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/23 16:16:00 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (dest == 0 && size == 0)
		return (0);
	while (dest[j] && j < size)
		j++;
	while (src[i] && size && j + i < size - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	if (j < size)
		dest[j + i] = '\0';
	while (src[i])
		i ++;
	return (j + i);
}
