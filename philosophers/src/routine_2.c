/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:02:35 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/30 18:02:36 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	display_status(t_philosopher *philosopher, const char *status)
{
	pthread_mutex_lock(philosopher->write_lock);
	printf("%zu %d %s\n", get_current_timestamp()
		- philosopher->simulation->start_time, philosopher->id, status);
	pthread_mutex_unlock(philosopher->write_lock);
}

void	pick_up_even_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->right_fork);
	if (!is_simulation_stopped(philosopher))
		display_status(philosopher, "has taken a fork");
	pthread_mutex_lock(philosopher->left_fork);
	if (!is_simulation_stopped(philosopher))
		display_status(philosopher, "has taken a fork");
}

void	pick_up_odd_forks(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->left_fork);
	if (!is_simulation_stopped(philosopher))
		display_status(philosopher, "has taken a fork");
	pthread_mutex_lock(philosopher->right_fork);
	if (!is_simulation_stopped(philosopher))
		display_status(philosopher, "has taken a fork");
}
