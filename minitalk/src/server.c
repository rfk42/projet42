/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:42:23 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/13 18:16:08 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(char c)
{
	static char	*s = NULL;

	if (c)
		s = ft_strjoin(s, c);
	else
	{
		ft_putstr(s);
		ft_putstr("\n");
		free(s);
		s = NULL;
	}
}

void	sig_handler_server(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	count_bit = 0;

	if (signum == SIGUSR2)
		c = (c << 1) | 1;
	else if (signum == SIGUSR1)
		c = c << 1;
	if (count_bit < 7)
		count_bit++;
	else
	{
		bin_to_char(c);
		count_bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID of the server : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
		pause();
	return (0);
}
