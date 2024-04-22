/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:07:00 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/17 03:13:01 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **a)
{
	t_list	*head;
	t_list	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		last = ft_lstlast(*a);
		head = *a;
		*a = (*a)->next;
		last->next = head;
		head->next = NULL;
	}
}

void	reverse_rotate(t_list **a)
{
	t_list	*head;
	t_list	*last;
	t_list	*b_last;

	if (*a != NULL && (*a)->next != NULL)
	{
		head = *a;
		last = ft_lstlast(*a);
		while ((*a)->next != NULL)
		{
			b_last = (*a);
			(*a) = (*a)->next;
		}
		last->next = (head);
		b_last->next = NULL;
	}
}

void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = tmp;
	}
}

void	swap(t_list **a)
{
	t_list	*tmp;

	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = (*a);
		(*a) = tmp;
	}
}

void	ra(t_list **lst)
{
	rotate(lst);
	ft_putstr("ra\n");
}

/*t_list *tmp;
t_list *tmpb;
t_list *tmpa;

tmp = (*a)->next->next;
tmpb = (*a)->next;
tmpa = (*a);
(*a) = tmpb;
tmpb->next = tmpa;
tmpa->next = tmp;*/