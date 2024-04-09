/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:32:13 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/09 08:51:41 by rhamini          ###   ########.fr       */
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

t_list	*find_kawainee(t_list *lst)
{
	t_list	*tmp;
	t_list	*kawainee;

	tmp = lst;
	kawainee = lst;
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->value > kawainee->value)
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

	tmp = lst;
	baka = lst;
	if (!lst)
		return (NULL);
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
