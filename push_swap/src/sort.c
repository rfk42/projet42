/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:25:01 by rhamini           #+#    #+#             */
/*   Updated: 2024/06/07 13:06:35 by rhamini          ###   ########.fr       */
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

int	push_all_b(t_list **a, t_list **b, int ac)
{
	int	m;

	m = lst_mediane(*a);
	if (lst_len(*a) > 3)
	{
		if (lst_len(*a) > 100)
		{
			push_median(a, b);
			push_pre_sort(a, b, m);
		}
		else
			push_pre_sort(a, b, m);
		return (1);
	}
	else
	{
		kawai_sort(a);
		return (0);
	}
	(void)ac;
}

void	get_tourniquet_ready(t_list **a, t_list *good_case, int b)
{
	int	mid;

	mid = lst_len(*a) / 2;
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
	else if ((hess->index > mid_b) && (hess->target->index > mid_b))
		reverse_tourniquet(a, b, hess);
	get_tourniquet_ready(a, hess->target, 'a');
	get_tourniquet_ready(b, hess, 0);
	pa(b, a);
}

void	ft_sort(t_list **a, t_list **b, int ac)
{
	t_list	*kawainee;
	int		mid;

	if (!push_all_b(a, b, ac))
		return ;
	while (*b)
	{
		setup(a, b);
		salem_3lek(a, b);
	}
	kawainee = find_kawainee(*a);
	lst_index(kawainee);
	mid = lst_len(*a) / 2;
	if (kawainee->index <= mid)
		while (*a != kawainee)
			ra(a);
	else
		while (*a != kawainee)
			rra(a);
}

/*	printf("valeur de kawainee : %d\n", kawainee->value);
	printf("index de kawainee : %d\n", kawainee->index);*/