/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:22 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:39:22 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	if (dead_loop(philo))
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(&philo->meal_lock);
		return ;
	}
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	philo->eating = 1;
	print_status(philo, "is eating");
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep2(philo->time_to_eat, philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	think(t_philo *philo)
{
	if (!dead_loop(philo))
	{
		print_status(philo, "is thinking");
		ft_usleep2(philo->t_think, philo);
	}
}

void	ft_slip(t_philo *philo)
{
	if (!dead_loop(philo))
	{
		print_status(philo, "is sleeping");
		ft_usleep2(philo->time_to_sleep, philo);
	}
}

int	only_one(t_philo *philo)
{
	if (philo->program->num_philos == 1)
	{
		print_status(philo, "has taken a fork");
		ft_usleep2(philo->time_to_die, philo);
		print_status(philo, "died");
		return (1);
	}
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->program->m_time);
	philo->program->start_time = get_current_time();
	pthread_mutex_unlock(&philo->program->m_time);
	if (only_one(philo))
		return (NULL);
	wait_threads(philo);
	usleep(100);
	if (philo->id % 2 == 0)
		ft_usleep2(philo->time_to_eat, philo);
	while (!dead_loop(philo))
	{
		if (philo->id % 2 == 1)
			pick_up_forks_odd(philo);
		else
			pick_up_forks_even(philo);
		eat(philo);
		ft_slip(philo);
		think(philo);
		usleep(100);
	}
	return (NULL);
}
