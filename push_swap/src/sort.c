/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:25:01 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/09 09:24:00 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	kawai_sort(t_list **a)
{
	t_list	*baka;

	baka = find_baka(*a);
	if (*a == baka)
		rotate(a);
	else if ((*a)->next == baka)
		reverse_rotate(a);
	if ((*a)->value > (*a)->next->value)
		swap(a);
}

void	push_all_b(t_list **a, t_list **b, int ac)
{
	while (ac > 4)
	{
		push(a, b);
		ac--;
	}
}

void	ft_sort(t_list **a, t_list **b, int ac)
{
	push_all_b(a, b, ac);
	kawai_sort(a);
//	lst_index(*a);
//	lst_index(*b);
//	lst_target(a, b);
//	lst_cost(a, b);
}
/*
fct qui trouve les index
fct qui trouve une cible
fct pour le cout
*/