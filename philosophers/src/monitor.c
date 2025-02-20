/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:47 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 14:32:26 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_simulation_stopped(t_philosopher *philosopher)
{
	int	is_stopped;

	pthread_mutex_lock(&philosopher->simulation->death_lock);
	is_stopped = philosopher->simulation->is_stopped;
	pthread_mutex_unlock(&philosopher->simulation->death_lock);
	return (is_stopped);
}

int	check_death_conditions(t_philosopher *philosopher,
		t_simulation *simulation, size_t die_time_limit)
{
	if (get_current_timestamp() - philosopher->last_meal_time
		>= die_time_limit / 1000 && philosopher->is_eating == 0)
	{
		simulation->is_dead_flag = 1;
		philosopher->is_dead = 1;
		simulation->is_stopped = 1;
		display_status(philosopher, "died");
		return (1);
	}
	return (0);
}

int	check_philosopher_death(t_philosopher *philosopher,
		t_simulation *simulation, size_t die_time_limit)
{
	int	is_dead;

	pthread_mutex_lock(&philosopher->meal_lock);
	pthread_mutex_lock(&philosopher->simulation->death_lock);
	is_dead = check_death_conditions(philosopher, simulation, die_time_limit);
	pthread_mutex_unlock(&philosopher->simulation->death_lock);
	pthread_mutex_unlock(&philosopher->meal_lock);
	return (is_dead);
}

int	check_all_ate(t_simulation *simulation)
{
	int	all_ate;
	int	i;

	all_ate = 1;
	i = 0;
	while (i < simulation->total_philosophers)
	{
		pthread_mutex_lock(&simulation->philosophers[i].meal_lock);
		if (simulation->meals_required
			> simulation->philosophers[i].meals_eaten)
		{
			all_ate = 0;
			pthread_mutex_unlock(&simulation->philosophers[i].meal_lock);
			break ;
		}
		pthread_mutex_unlock(&simulation->philosophers[i].meal_lock);
		i++;
	}
	return (all_ate);
}

void	*monitor_simulation(void *arg)
{
	t_simulation	*simulation;
	int				i;

	simulation = (t_simulation *)arg;
	wait_for_start(simulation->philosophers);
	while (1)
	{
		i = 0;
		while (i < simulation->total_philosophers)
		{
			if (check_philosopher_death(&simulation->philosophers[i],
					simulation, simulation->philosophers[i].die_time_limit))
				exit(1);
			i++;
		}
		if (simulation->meals_required != -1 && check_all_ate(simulation))
		{
			pthread_mutex_lock(&simulation->death_lock);
			simulation->is_stopped = 1;
			pthread_mutex_unlock(&simulation->death_lock);
			exit(1);
		}
		usleep(500);
	}
	return (NULL);
}
