/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:38:25 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:38:25 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo_threads(t_program *program, int num_philos)
{
	int	i;

	i = 0;
	program->start = 0;
	while (i < num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, philo_routine,
				&program->philos[i]) != 0)
		{
			perror("Failed to create philosopher thread");
			destroy_program(program);
			exit(1);
		}
		pthread_mutex_lock(&program->ready);
		if (i == num_philos - 1)
			program->start = 1;
		pthread_mutex_unlock(&program->ready);
		i++;
	}
}

void	join_philo_threads(t_program *program, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
		{
			perror("Failed to join philosopher thread");
			destroy_program(program);
			exit(1);
		}
		i++;
	}
}

void	*monitor_philos(void *arg)
{
	t_program	*program;
	pthread_t	monitor_thread;

	program = (t_program *)arg;
	if (program->num_philos != 1)
	{
		if (pthread_create(&monitor_thread, NULL, monitor, program) != 0)
		{
			perror("Failed to create monitor thread");
			destroy_program(program);
			exit(1);
		}
		if (pthread_join(monitor_thread, NULL) != 0)
		{
			perror("Failed to join monitor thread");
			destroy_program(program);
			exit(1);
		}
	}
	return (NULL);
}
