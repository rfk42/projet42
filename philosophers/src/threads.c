/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:02:25 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 14:31:04 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	create_philo_threads(t_simulation *simulation, int total_philosophers)
{
	int	i;

	i = 0;
	simulation->is_started = 0;
	while (i < total_philosophers)
	{
		if (pthread_create(&simulation->philosophers[i].thread, NULL,
				philosopher_routine, &simulation->philosophers[i]) != 0)
		{
			printf("Failed to create philosopher thread");
			destroy_simulation(simulation);
			exit(1);
		}
		pthread_mutex_lock(&simulation->ready_lock);
		if (i == total_philosophers - 1)
			simulation->is_started = 1;
		pthread_mutex_unlock(&simulation->ready_lock);
		i++;
	}
}

void	join_philo_threads(t_simulation *simulation, int total_philosophers)
{
	int	i;

	i = 0;
	while (i < total_philosophers)
	{
		if (pthread_join(simulation->philosophers[i].thread, NULL) != 0)
		{
			printf("Failed to join philosopher thread");
			destroy_simulation(simulation);
			exit(1);
		}
		i++;
	}
}

void	*monitor_philosophers(void *arg)
{
	t_simulation	*simulation;
	pthread_t		monitor_thread;

	simulation = (t_simulation *)arg;
	if (simulation->total_philosophers != 1)
	{
		if (pthread_create(&monitor_thread, NULL, monitor_simulation,
				simulation) != 0)
		{
			printf("Failed to create monitor thread");
			destroy_simulation(simulation);
			return (NULL);
		}
		if (pthread_join(monitor_thread, NULL) != 0)
		{
			printf("Failed to join monitor thread");
			destroy_simulation(simulation);
			return (NULL);
		}
	}
	return (NULL);
}
