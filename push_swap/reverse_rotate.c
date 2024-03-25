/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:12 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/25 15:32:55 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate(t_list **a)
{
	t_list *head;
	t_list *last;
	
	last = ft_lstlast(*a);
	head = *a;
	*a = (*a)->next;
	last->next = head;
	head->next = NULL;
}



void	reverse_rotate(t_list **a)
{
	t_list *head;
	t_list *tmplast;
	t_list **last;
	t_list *b_last;


	head = *a;
	*last = ft_lstlast(*a);
	(*last)->next = *a;

	while((*a)->next != *last) 	
	{	
		b_last = *a;
		*a = (*a)->next;
	}
	(*a)->next= NULL;
	
}

