/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:36:39 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/22 17:24:20 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>



void	ft_putstr(char *s);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char const c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putchar(char c);
int		ft_strcmp(const char *s1, const char *s2);
void	free_tab(char **av);

#endif