/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:05:24 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 13:38:00 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	initialize_global_mutexes(t_simulation *simulation)
{
	pthread_mutex_init(&simulation->death_lock, NULL);
	pthread_mutex_init(&simulation->meal_lock, NULL);
	pthread_mutex_init(&simulation->write_lock, NULL);
	pthread_mutex_init(&simulation->ready_lock, NULL);
	pthread_mutex_init(&simulation->time_lock, NULL);
}

void	initialize_forks(t_simulation *simulation, int total_philosophers)
{
	int	i;

	simulation->forks = malloc(total_philosophers * sizeof(pthread_mutex_t));
	if (simulation->forks == NULL)
		return ;
	i = 0;
	while (i < total_philosophers)
	{
		pthread_mutex_init(&simulation->forks[i], NULL);
		i++;
	}
}

void	initialize_philosophers(t_simulation *simulation, size_t die_time_limit,
		size_t eat_duration, size_t sleep_duration)
{
	simulation->philosophers = malloc(simulation->total_philosophers
			* sizeof(t_philosopher));
	if (simulation->philosophers == NULL)
	{
		free(simulation->forks);
		return ;
	}
	simulation->start_time = get_current_timestamp();
	initialize_philosopher_details(simulation, die_time_limit, eat_duration,
		sleep_duration);
	simulation->is_stopped = 0;
}

void	initialize_simulation(t_simulation *simulation, size_t die_time_limit,
		size_t eat_duration, size_t sleep_duration)
{
	simulation->is_dead_flag = 0;
	initialize_global_mutexes(simulation);
	initialize_forks(simulation, simulation->total_philosophers);
	initialize_philosophers(simulation, die_time_limit, eat_duration,
		sleep_duration);
}

void	destroy_simulation(t_simulation *simulation)
{
	int	i;

	i = 0;
	while (i < simulation->total_philosophers)
	{
		pthread_mutex_destroy(&simulation->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&simulation->death_lock);
	pthread_mutex_destroy(&simulation->meal_lock);
	pthread_mutex_destroy(&simulation->write_lock);
	pthread_mutex_destroy(&simulation->ready_lock);
	pthread_mutex_destroy(&simulation->time_lock);
	free(simulation->philosophers);
	free(simulation->forks);
}
