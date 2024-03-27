/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:25 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/27 13:51:44 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **a)
{
	// t_list *tmp;
	// t_list *tmpb;
	// t_list *tmpa;


	// tmp = (*a)->next->next;
	
	// tmpb = (*a)->next;
	// tmpa = (*a);
	// (*a) = tmpb;
	// tmpb->next = tmpa;
	// tmpa->next = tmp;

	t_list *tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = (*a);
	(*a) = tmp;
}