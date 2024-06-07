/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:10 by rhamini           #+#    #+#             */
/*   Updated: 2024/05/09 02:02:09 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(int *tab, unsigned int len)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < (len - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	lst_mediane(t_list *a)
{
	int		len;
	int		i;
	int		median;
	t_list	*tmp;
	int		*tab;

	len = lst_len(a);
	i = 0;
	tab = (int *)malloc(len * sizeof(int));
	tmp = a;
	while (i < len)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_int_tab(tab, len);
	if (len % 2 == 0)
		median = (tab[len / 2 - 1] + tab[len / 2]) / 2;
	else
		median = tab[len / 2];
	free(tab);
	return (median);
}

void	push_median(t_list **a, t_list **b)
{
	int		kawai;
	t_list	*tmp;
	int		median;

	kawai = 0;
	median = lst_mediane(*a);
	tmp = *a;
	while (tmp && tmp->value != median)
	{
		tmp = tmp->next;
		kawai++;
	}
	if (kawai <= lst_len(*a) - kawai)
	{
		while (*a && (*a)->value != median)
			ra(a);
	}
	else
	{
		kawai = lst_len(*a) - kawai;
		while (kawai--)
			rra(a);
	}
	pb(a, b);
}

void	push_pre_sort(t_list **a, t_list **b, int m)
{
	int		size_a;
	int		i;
	t_list	*baka;

	i = 0;
	baka = find_baka(*a);
	size_a = lst_len(*a);
	if (size_a == 1)
		return ;
	while (i < size_a)
	{
		if ((*a)->value != baka->value)
		{
			pb(a, b);
			if ((*b)->value > m)
				rb(b);
		}
		else
			ra(a);
		i++;
	}
}
