/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:34 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 13:29:29 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	initialize_simulation_parameters(t_simulation *simulation,
			int ac, char **av)
{
	simulation->total_philosophers = ft_atol(av[1]);
	simulation->die_time_limit = ft_atol(av[2]) * 1000;
	simulation->eat_duration = ft_atol(av[3]) * 1000;
	simulation->sleep_duration = ft_atol(av[4]) * 1000;
	if (ac == 6)
		simulation->meals_required = ft_atol(av[5]);
	else
		simulation->meals_required = -1;
}

void	configure_philosopher(int i, t_simulation *simulation)
{
	simulation->philosophers[i].id = i + 1;
	simulation->philosophers[i].is_eating = 0;
	simulation->philosophers[i].meals_eaten = 0;
	simulation->philosophers[i].last_meal_time = get_current_timestamp();
	simulation->philosophers[i].right_fork = &simulation->forks[i];
	simulation->philosophers[i].left_fork = &simulation->forks[(i + 1)
		% simulation->total_philosophers];
	pthread_mutex_init(&simulation->philosophers[i].meal_lock, NULL);
	pthread_mutex_init(&simulation->philosophers[i].death_lock, NULL);
	simulation->philosophers[i].write_lock = &simulation->write_lock;
	simulation->philosophers[i].simulation = simulation;
}

void	initialize_philosopher_details(t_simulation *simulation,
		size_t die_time_limit, size_t eat_duration, size_t sleep_duration)
{
	int	i;

	i = 0;
	while (i < simulation->total_philosophers)
	{
		configure_philosopher(i, simulation);
		simulation->philosophers[i].die_time_limit = die_time_limit;
		simulation->philosophers[i].eat_duration = eat_duration;
		simulation->philosophers[i].sleep_duration = sleep_duration;
		simulation->philosophers[i].meals_required = simulation->meals_required;
		if (eat_duration > sleep_duration)
			simulation->philosophers[i].think_duration = (eat_duration
					- sleep_duration) + 1000;
		else
			simulation->philosophers[i].think_duration = 1000;
		i++;
	}
}
