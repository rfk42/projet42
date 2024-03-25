/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 03:40:36 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/21 10:31:13 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = src;

	d = dest;
	if (dest == 0 && src == 0)
		return (NULL);
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (n > 0)
		{
			*d = *s;
			d++;
			s++;
			n--;
		}
	}
	return (dest);
}

/*int main()
{
	char buffer[20] = "Helloooooooo, World!";
	char buffer2[20] = "Helloooooooo, World!";

	memmove(buffer, buffer + 10, 13);
	printf("%s\n", buffer);

	ft_memmove(buffer2, buffer2 + 10, 13);
	printf("%s\n", buffer2);

}*/