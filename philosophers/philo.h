/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:51:05 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 13:26:59 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

// Forward declaration
struct	s_simulation;

typedef struct s_philosopher
{
	pthread_t			thread;
	int					id;
	int					is_eating;
	int					meals_eaten;
	size_t				last_meal_time;
	size_t				die_time_limit;
	size_t				eat_duration;
	size_t				think_duration;
	size_t				sleep_duration;
	int					meals_required;
	int					is_dead;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		death_lock;
	pthread_mutex_t		meal_lock;
	struct s_simulation	*simulation;
}	t_philosopher;

typedef struct s_simulation
{
	size_t			die_time_limit;
	size_t			eat_duration;
	size_t			sleep_duration;
	int				is_stopped;
	int				is_started;
	size_t			start_time;
	int				meals_required;
	int				total_philosophers;
	int				is_dead_flag;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	ready_lock;
	pthread_mutex_t	time_lock;
	t_philosopher	*philosophers;
}	t_simulation;

// Fonction principale pour initialiser la simulation
void	initialize_simulation_parameters(t_simulation *simulation,
			int ac, char **av);
void	initialize_simulation(t_simulation *simulation,
			size_t die_time_limit, size_t eat_duration, size_t sleep_duration);
void	destroy_simulation(t_simulation *simulation);

// Gestion des threads
void	create_philo_threads(t_simulation *simulation, int total_philosophers);
void	join_philo_threads(t_simulation *simulation, int total_philosophers);
void	*monitor_simulation(void *arg);
void	*monitor_philosophers(void *arg);

// Fonctionnalités des philosophes
int		custom_usleep(size_t time);
void	display_status(t_philosopher *philosopher, const char *status);
void	philosopher_eat(t_philosopher *philosopher);
void	*philosopher_routine(void *arg);
int		check_philosopher_death(t_philosopher *philosopher,
			t_simulation *simulation, size_t die_time_limit);
int		check_all_ate(t_simulation *simulation);

// Initialisation des ressources
void	initialize_global_mutexes(t_simulation *simulation);
void	initialize_forks(t_simulation *simulation, int num_philosophers);
void	initialize_philosophers(t_simulation *simulation,
			size_t die_time_limit, size_t eat_duration, size_t sleep_duration);
void	initialize_philosopher_details(t_simulation *simulation,
			size_t die_time_limit, size_t eat_duration, size_t sleep_duration);
size_t	get_current_timestamp(void);

// Boucles et routines
int		is_simulation_stopped(t_philosopher *philosopher);
void	philosopher_think(t_philosopher *philosopher);
void	philosopher_sleep(t_philosopher *philosopher);

// Utilitaires
long	ft_atol(const char *str);
int		is_valid_number(char *str);
int		is_ready(t_philosopher *philosopher);
void	wait_for_start(t_philosopher *philosopher);
void	custom_usleep_2(int duration, t_philosopher *philosopher);

// Gestion des fourchettes
void	pick_up_even_forks(t_philosopher *philosopher);
void	pick_up_odd_forks(t_philosopher *philosopher);

#endif
