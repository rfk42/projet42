/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:58:03 by rhamini           #+#    #+#             */
/*   Updated: 2024/03/21 10:32:02 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char spec, va_list args)
{
	int	final_len;

	final_len = 0;
	if (spec == 'c')
		final_len += ft_printchar(va_arg(args, int));
	if (spec == '%')
		final_len += ft_printchar('%');
	else if (spec == 's')
		final_len += ft_prints(va_arg(args, char *));
	else if (spec == 'd')
		final_len += ft_printd(va_arg(args, int));
	else if (spec == 'i')
		final_len += ft_printd(va_arg(args, int));
	else if (spec == 'u')
		final_len += ft_printui(va_arg(args, int));
	else if (spec == 'p')
		final_len += ft_printptr(va_arg(args, unsigned long long));
	else if (spec == 'x' || spec == 'X')
		final_len += ft_printhex(va_arg(args, unsigned int), spec);
	return (final_len);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	i;
	int				final_len;

	i = 0;
	final_len = 0;
	va_start(args, str);
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			final_len += check(str[i + 1], args);
			i++;
		}
		else
			final_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (final_len);
}
