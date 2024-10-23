/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:38:36 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:38:39 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d %s\n", get_current_time() - philo->program->start_time,
		philo->id, status);
	pthread_mutex_unlock(philo->write_lock);
}

void	pick_up_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (!dead_loop(philo))
		print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	if (!dead_loop(philo))
		print_status(philo, "has taken a fork");
}

void	pick_up_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (!dead_loop(philo))
		print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	if (!dead_loop(philo))
		print_status(philo, "has taken a fork");
}
