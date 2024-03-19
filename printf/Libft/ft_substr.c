/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 00:21:50 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/20 01:43:40 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	unsigned int	t;
	char			*s2;

	t = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start > slen)
		return (ft_strdup(""));
	s = s + start;
	while (s[t] && len--)
		t++;
	s2 = malloc(sizeof(char) * (t + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s, t + 1);
	return (s2);
}
