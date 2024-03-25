/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:23 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/25 14:53:22 by rhamini          ###   ########.fr       */
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

