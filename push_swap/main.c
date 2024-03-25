/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/25 15:11:34 by rhamini          ###   ########.fr       */
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
		printf("addr  = %p\n", lst);
		printf("addr next = %p\n", lst->next);
		printf("\n");
		lst = lst->next;
	}
}


int main (void)
{
	t_list *a;

	a = ft_lstnew(213);
	ft_lstadd_back(a, 34);
	ft_lstadd_back(a, 33);
	ft_lstadd_back(a, 36);
	ft_lstadd_back(a, 3434);
	ft_lstadd_back(a, 368);	
	ft_lstadd_back(a, 434);


	ft_lstiter(a);

	printf("\n\n");
	reverse_rotate(&a);
	ft_lstiter(a);
}