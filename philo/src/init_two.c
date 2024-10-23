/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:40:01 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:40:02 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	int_tree(int i, t_program *program)
{
	program->philos[i].id = i + 1;
	program->philos[i].eating = 0;
	program->philos[i].meals_eaten = 0;
	program->philos[i].last_meal = get_current_time();
}

void	init_two(t_program *program, size_t time_to_die, size_t time_to_eat,
		size_t time_to_sleep)
{
	int	i;

	i = 0;
	while (i < program->num_philos)
	{
		int_tree(i, program);
		program->philos[i].time_to_die = time_to_die;
		program->philos[i].time_to_eat = time_to_eat;
		program->philos[i].time_to_sleep = time_to_sleep;
		program->philos[i].num_times_to_eat = -1;
		program->philos[i].r_fork = &program->forks[i];
		program->philos[i].l_fork = &program->forks[(i + 1)
			% program->num_philos];
		program->philos[i].write_lock = &program->write_lock;
		program->philos[i].dead_lock = program->dead_lock;
		program->philos[i].meal_lock = program->meal_lock;
		program->philos[i].program = program;
		if (program->philos[i].time_to_eat > program->philos[i].time_to_sleep)
			program->philos[i].t_think = (program->philos[i].time_to_eat
					- program->philos[i].time_to_sleep) + 1000;
		else
			program->philos[i].t_think = 1000;
		i++;
	}
}
