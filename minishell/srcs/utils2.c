/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:04:24 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/21 23:42:22 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0' || s2[i] != '\0')))
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

void	free_tab(char **av)
{
	int	i;

	i = 0;
	if (!av || !(*av))
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av - 1);
	return ;
}