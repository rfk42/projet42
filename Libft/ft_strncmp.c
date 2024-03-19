/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 01:34:17 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/23 13:13:55 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0' || s2[i] != '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
		{
			return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)
			(s2 + i)));
		}
		i++;
	}
	return (0);
}
