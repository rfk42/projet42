/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:12 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/27 13:51:32 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **a)
{
	t_list *head;
	t_list *last;
	t_list *b_last;


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
