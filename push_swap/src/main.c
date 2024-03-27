/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/27 15:05:24 by rhamini          ###   ########.fr       */
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

int	check_input(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' )
			j++;
		}
		i++;
	}
	return 1;
}

t_list	*ft_fill(char **av)
{
	t_list *a;
	int	i;

	i = 1;
	a = ft_lstnew(atoi(av[i]));
	i++;
	while (av[i])
	{
		ft_lstadd_back(a, atoi(av[i]));
		i++;
	}
	return a;
}

int main (int ac, char **av)
{
	t_list *a;
	
	check_input(av);	
	a = ft_fill(av);
	
	check_input(a);
	
	ft_lstiter(a);

	printf("\n\n");
	swap(&a);

	printf("\n\n");
	ft_lstiter(a);
	(void)ac;

}