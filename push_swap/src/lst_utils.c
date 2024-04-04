/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:05:26 by rhamini           #+#    #+#             */
/*   Updated: 2024/04/04 15:19:46 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list *alst, int b)
{
	if (!alst)
		return ;
	if (alst)
		ft_lstlast(alst)->next = ft_lstnew(b);
}

void	ft_lstiter(t_list *lst)
{
	while (lst)
	{
		printf("value = %d\n", lst->value);
		// printf("addr  = %p\n", lst);
		// printf("addr next = %p\n", lst->next);
		// printf("\n");
		printf("target = %d\n", lst->index);
		printf("index = %d\n", lst->index);
		printf("\n");
		printf("\n");
		lst = lst->next;
	}
}
