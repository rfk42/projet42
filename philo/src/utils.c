/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:38:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:38:15 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+')
		i++;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

int	philo_is_ready(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&philo->program->ready);
	ret = philo->program->start;
	pthread_mutex_unlock(&philo->program->ready);
	return (ret);
}

void	wait_threads(t_philo *philo)
{
	while (philo_is_ready(philo) == 0)
		usleep(500);
}

void	ft_usleep2(int time_to, t_philo *philo)
{
	int	pourcent;

	pourcent = 0.1 * time_to;
	while (time_to > 0 && dead_loop(philo) == 0)
	{
		usleep(pourcent);
		time_to -= pourcent;
	}
}
