/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:02:30 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/30 18:03:59 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philosopher_eat(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->meal_lock);
	if (is_simulation_stopped(philosopher))
	{
		pthread_mutex_unlock(philosopher->right_fork);
		pthread_mutex_unlock(philosopher->left_fork);
		pthread_mutex_unlock(&philosopher->meal_lock);
		return ;
	}
	philosopher->last_meal_time = get_current_timestamp();
	philosopher->meals_eaten++;
	philosopher->is_eating = 1;
	display_status(philosopher, "is eating");
	pthread_mutex_unlock(&philosopher->meal_lock);
	custom_usleep_2(philosopher->eat_duration, philosopher);
	pthread_mutex_lock(&philosopher->meal_lock);
	philosopher->is_eating = 0;
	pthread_mutex_unlock(&philosopher->meal_lock);
	pthread_mutex_unlock(philosopher->left_fork);
	pthread_mutex_unlock(philosopher->right_fork);
}

void	philosopher_think(t_philosopher *philosopher)
{
	if (!is_simulation_stopped(philosopher))
	{
		display_status(philosopher, "is thinking");
		custom_usleep_2(philosopher->think_duration, philosopher);
	}
}

void	philosopher_sleep(t_philosopher *philosopher)
{
	if (!is_simulation_stopped(philosopher))
	{
		display_status(philosopher, "is sleeping");
		custom_usleep_2(philosopher->sleep_duration, philosopher);
	}
}

int	only_one_philosopher(t_philosopher *philosopher)
{
	if (philosopher->simulation->total_philosophers == 1)
	{
		display_status(philosopher, "has taken a fork");
		custom_usleep_2(philosopher->die_time_limit, philosopher);
		display_status(philosopher, "died");
		return (1);
	}
	return (0);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)arg;
	pthread_mutex_lock(&philosopher->simulation->time_lock);
	philosopher->simulation->start_time = get_current_timestamp();
	pthread_mutex_unlock(&philosopher->simulation->time_lock);
	if (only_one_philosopher(philosopher))
		return (NULL);
	wait_for_start(philosopher);
	usleep(100);
	if (philosopher->id % 2 == 0)
		custom_usleep_2(philosopher->eat_duration, philosopher);
	while (!is_simulation_stopped(philosopher))
	{
		if (philosopher->id % 2 == 1)
			pick_up_odd_forks(philosopher);
		else
			pick_up_even_forks(philosopher);
		philosopher_eat(philosopher);
		philosopher_sleep(philosopher);
		philosopher_think(philosopher);
		usleep(100);
	}
	return (NULL);
}
