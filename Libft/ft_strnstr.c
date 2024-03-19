/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:22:35 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/23 16:10:23 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s1 == 0 && n == 0)
		return (NULL);
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && (i <= n))
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j < n))
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
