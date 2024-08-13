/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:32:22 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/13 14:24:02 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *s);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char const c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_putchar(char c);

#endif