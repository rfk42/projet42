/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:25:01 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/17 17:05:50 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	kawai_sort(t_list **a)
{
	t_list	*baka;

	baka = find_baka(*a);
	if (*a == baka)
		ra(a);
	else if ((*a)->next == baka)
		rra(a);
	if ((*a)->value > (*a)->next->value)
	{
		swap(a);
		ft_putstr("sa\n");
	}
}

void	push_all_b(t_list **a, t_list **b, int ac)
{
	while (ac > 4)
	{
		pb(a, b);
		ac--;
	}
}

void	get_tourniquet_ready(t_list **a, t_list *good_case, int b)
{
	int	mid;

	mid = lst_len(good_case) / 2;
	while (*a != good_case)
	{
		if (b)
		{
			if (good_case->index <= mid)
				ra(a);
			else
				rra(a);
		}
		else
		{
			if (good_case->index <= mid)
				rb(a);
			else
				rrb(a);
		}
	}
}

void	salem_3lek(t_list **a, t_list **b)
{
	t_list	*hess;
	int		mid_b;

	hess = get_hess(*b);
	mid_b = lst_len(*b) / 2;
	if (hess->index <= mid_b && hess->target->index <= mid_b)
		oh_tourniquet(a, b, hess);
	else
		reverse_tourniquet(a, b, hess);
	get_tourniquet_ready(a, hess->target, 'a');
	get_tourniquet_ready(b, hess, 0);
	pa(b, a);
}

void	ft_sort(t_list **a, t_list **b, int ac)
{
	t_list	*kawainee;
	int		mid;

	push_all_b(a, b, ac);
	if (ac >= 4)
		kawai_sort(a);
	while (*b)
	{
		setup(a, b);
		salem_3lek(a, b);
	}
	kawainee = find_kawainee(*a);
	lst_index(kawainee);
	mid = lst_len(*a) / 2;
	if (kawainee->index <= mid)
	{
		while (*a != kawainee)
			ra(a);
	}
	else
	{
		while (*a != kawainee)
			rra(a);
	}
}
