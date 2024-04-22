/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:07:00 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/22 15:08:46 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **lst)
{
	rotate(lst);
	ft_putstr("rb\n");
}

void	rra(t_list **lst)
{
	reverse_rotate(lst);
	ft_putstr("rra\n");
}

void	rrb(t_list **lst)
{
	reverse_rotate(lst);
	ft_putstr("rrb\n");
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr("pb\n");
}
