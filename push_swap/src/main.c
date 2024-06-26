/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/05/08 03:06:37 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_list	*ft_fill(char **av)
{
	t_list	*a;
	int		i;

	i = 1;
	a = ft_lstnew(ft_atoi(av[i]));
	i++;
	while (av[i])
	{
		ft_lstadd_back(a, ft_atoi(av[i]));
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!check_input(ac, av + 1))
		a = ft_fill(av);
	if (a != NULL && (!(is_sorted(a))))
		ft_sort(&a, &b, ac);
	free_lst(&a);
}
