/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:01:42 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/27 13:52:05 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int			value;
	struct s_list	*next;
}					t_list;


//----- utils

t_list	*ft_lstlast(t_list *lst);


//-----------opertatotd

void	rotate(t_list **a);
void	reverse_rotate(t_list **a);
void 	push(t_list **a, t_list **b);
void	swap(t_list **a);

#endif