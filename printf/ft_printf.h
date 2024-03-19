/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:55:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/01/16 18:07:47 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./Libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printd(int n);
int		ft_prints(char *s);
int		ft_printui(unsigned int nb);
int		ft_printptr(unsigned long long ptr);
int		ft_printhex(unsigned int num, const char format);

#endif