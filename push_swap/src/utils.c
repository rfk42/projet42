/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:12:44 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/24 18:20:41 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
		i++;
	write(1, s, i);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	long	nbr;

	i = 0;
	signe = 1;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (nbr * signe);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	if (lst)
		free(lst);
}

void	free_lst(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
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
