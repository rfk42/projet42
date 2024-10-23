/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:53 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:39:53 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_global_mutexes(t_program *program)
{
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->ready, NULL);
	pthread_mutex_init(&program->m_time, NULL);
}

void	init_forks(t_program *program, int num_philos)
{
	int	i;

	program->forks = malloc(num_philos * sizeof(pthread_mutex_t));
	if (program->forks == NULL)
		exit(1);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&program->forks[i], NULL);
		i++;
	}
}

void	init_philosophers(t_program *program,
		size_t time_to_die, size_t time_to_eat, size_t time_to_sleep)
{
	(void)time_to_die;
	(void)time_to_eat;
	(void)time_to_sleep;
	program->philos = malloc(program->num_philos * sizeof(t_philo));
	if (program->philos == NULL)
	{
		free(program->forks);
		exit(1);
	}
	program->start_time = get_current_time();
	init_two(program, time_to_die, time_to_eat, time_to_sleep);
	program->stop = 0;
}

void	initialize_program(t_program *program,
		size_t time_to_die, size_t time_to_eat, size_t time_to_sleep)
{
	program->num_philos = program->num_philos;
	program->dead_flag = 0;
	init_global_mutexes(program);
	init_forks(program, program->num_philos);
	init_philosophers(program, time_to_die, time_to_eat,
		time_to_sleep);
}

void	destroy_program(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->num_philos)
	{
		pthread_mutex_destroy(&program->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->ready);
	pthread_mutex_destroy(&program->m_time);
	free(program->philos);
	free(program->forks);
}
