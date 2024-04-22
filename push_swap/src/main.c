/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/22 15:19:51 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	t_list	*tmp;
	t_list	*first;

	if (!a)
		return (1);
	first = a;
	tmp = a->next;
	while (tmp)
	{
		if (a->value > tmp->value)
			return (0);
		tmp = tmp->next;
		if (tmp == first)
			break ;
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
	ft_lstiter(a);
	free_lst(&a);
}
