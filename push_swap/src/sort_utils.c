/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:13 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/04 15:26:15 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_index(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
	lst->index = i;
}

void	lst_target(t_list *lst, t_list)
{
	int	i;

	i = 0;
	while (!lst->value)
	{
		lst->target = lst->value;
		lst = lst->next;
		i++;
	}
}


/*fct qui trouve les index
fct qui trouve une cible
fct pour le cout
*/