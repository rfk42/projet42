/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:02:15 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 13:20:31 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_ready(t_philosopher *philosopher)
{
	int	status;

	pthread_mutex_lock(&philosopher->simulation->ready_lock);
	status = philosopher->simulation->is_started;
	pthread_mutex_unlock(&philosopher->simulation->ready_lock);
	return (status);
}

void	wait_for_start(t_philosopher *philosopher)
{
	while (is_ready(philosopher) == 0)
		usleep(500);
}

void	custom_usleep_2(int duration, t_philosopher *philosopher)
{
	int	segment;

	segment = 0.1 * duration;
	while (duration > 0 && !is_simulation_stopped(philosopher))
	{
		usleep(segment);
		duration -= segment;
	}
}

int	custom_usleep(size_t milliseconds)
{
	size_t	start_time;

	start_time = get_current_timestamp();
	while ((get_current_timestamp() - start_time) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_timestamp(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("gettimeofday() error");
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
