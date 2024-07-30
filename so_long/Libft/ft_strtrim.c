/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:09 by rhamini           #+#    #+#             */
/*   Updated: 2023/11/20 16:26:34 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	int				i;
	int				j;
	int				k;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1 + i) - 1;
	while (j >= 0 && ft_strchr(set, s1[i + j]))
		j--;
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (NULL);
	while (k <= j)
	{
		str[k] = s1[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}
