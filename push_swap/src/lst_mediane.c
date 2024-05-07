/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_mediane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:53:10 by rhamini           #+#    #+#             */
/*   Updated: 2024/05/07 16:08:36 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_mediane(t_list *a)
{
	int		m;
	int		m2;
	int		len;
	t_list	*kawai;
	t_list	*baka;

	len = lst_len(a);
	kawai = find_kawainee(a);
	baka = find_baka(a);
	if (len % 2 == 0)
	{
		m = kawai->value + (baka->value - kawai->value) / 2;
		m2 = kawai->value + (baka->value - kawai->value) / 2 + 1;
		return ((m + m2) / 2);
	}
	else
		return (kawai->value + (baka->value - kawai->value) / 2);
}

void	lst_pre_tri(t_list **a, t_list **b, int m)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value > m)
		{
			pb(&tmp,b);
		}
		tmp = tmp->next;
	}
}