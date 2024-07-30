/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:42 by rhamini           #+#    #+#             */
/*   Updated: 2024/06/10 21:49:01 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				cout;
	int				index;
	struct s_list	*target;
	struct s_list	*next;
}					t_list;
//----- utils

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);
void	ft_lstdelone(t_list *lst);
int		lst_len(t_list *lst);
void	ft_lstadd_back(t_list *alst, int b);
void	ft_lstiter(t_list *lst);
void	ft_lstiterb(t_list *lst);
int		lst_mediane(t_list *a);
void	push_median(t_list **a, t_list **b);
void	push_pre_sort(t_list **a, t_list **b, int m);
t_list	*ft_fill(char **av);
long	ft_atoi(const char *str);
void	ft_putstr(char *s);
void	ft_putstr_error(char *s);
int		check_input(int ac, char **av);
void	lst_index(t_list *lst);
void	lst_target(t_list **lst, t_list **lst2);
void	lst_cost(t_list **lst, t_list **lst2);
void	lst_cost_utils(t_list *tmp, int len1, int len2, int mid1);
t_list	*get_hess(t_list *lst);
t_list	*find_kawainee(t_list *lst);
t_list	*find_baka(t_list *lst);
int		push_all_b(t_list **lst, t_list **lst2, int ac);
void	ft_sort(t_list **a, t_list **b, int ac);
void	salem_3lek(t_list **a, t_list **b);
void	setup(t_list **a, t_list **b);
void	oh_tourniquet(t_list **a, t_list **b, t_list *hess);
void	reverse_tourniquet(t_list **a, t_list **b, t_list *hess);
void	free_tab(char **av);
void	free_lst(t_list **lst);

//-----------operator

void	rotate(t_list **a);
void	reverse_rotate(t_list **a);
void	push(t_list **a, t_list **b);
void	swap(t_list **a);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

#endif