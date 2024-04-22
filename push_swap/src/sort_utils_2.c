/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:13 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/17 03:13:08 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_index(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
}

t_list	*find_kawainee(t_list *lst)
{
	t_list	*tmp;
	t_list	*kawainee;

	if (!lst)
		return (NULL);
	tmp = lst;
	kawainee = lst;
	while (lst)
	{
		if (lst->value < kawainee->value)
			kawainee = lst;
		lst = lst->next;
		if (lst == tmp)
			return (kawainee);
	}
	return (kawainee);
}

t_list	*find_baka(t_list *lst)
{
	t_list	*tmp;
	t_list	*baka;

	if (!lst)
		return (NULL);
	tmp = lst;
	baka = lst;
	while (lst)
	{
		if (lst->value > baka->value)
			baka = lst;
		lst = lst->next;
		if (lst == tmp)
			return (baka);
	}
	return (baka);
}

void	oh_tourniquet(t_list **a, t_list **b, t_list *hess)
{
	while (*a != hess->target && *b != hess)
	{
		rotate(a);
		rotate(b);
		ft_putstr("rr\n");
	}
	lst_index(*a);
	lst_index(*b);
}

void	reverse_tourniquet(t_list **a, t_list **b, t_list *hess)
{
	while (*a != hess->target && *b != hess)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		ft_putstr("rrr\n");
	}
	lst_index(*a);
	lst_index(*b);
}
