/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:40:12 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:40:12 by rhamini          ###   ########.fr       */
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

struct	s_program;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					meals_eaten;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				t_think;
	size_t				time_to_sleep;
	int					num_times_to_eat;
	int					dead;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	struct s_program	*program;
}	t_philo;

typedef struct s_program
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				stop;
	int				start;
	size_t			start_time;
	int				nb_must_eat;
	int				num_philos;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	pthread_mutex_t	ready;
	pthread_mutex_t	m_time;
	t_philo			*philos;
}	t_program;

void		initialize_program(t_program *program,
				size_t time_to_die, size_t time_to_eat, size_t time_to_sleep);
void		destroy_program(t_program *program);
void		create_philo_threads(t_program *program, int num_philos);
void		join_philo_threads(t_program *program, int num_philos);
void		*monitor(void *arg);
void		*monitor_philos(void *arg);

int			ft_usleep(size_t time);
void		print_status(t_philo *philo, const char *status);
void		eat(t_philo *philo);
void		*philo_routine(void *arg);
int			check_philo_death(t_philo *philo, t_program *program,
				size_t time_to_die);
int			check_all_philos_ate(t_program *program);
void		init_global_mutexes(t_program *program);
void		init_forks(t_program *program, int num_philos);
void		init_philosophers(t_program *program,
				size_t time_to_die, size_t time_to_eat, size_t time_to_sleep);
size_t		get_current_time(void);
int			dead_loop(t_philo *philo);
void		think(t_philo *philo);
void		ft_slip(t_philo *philo);
long int	ft_long_atoi(const char *nptr);
int			is_number(char *av);
void		parsing(char **av);
int			philo_is_ready(t_philo *philo);
void		wait_threads(t_philo *philo);
void		ft_usleep2(int time_to, t_philo *philo);
void		init_two(t_program *program, size_t time_to_die, size_t time_to_eat,
				size_t time_to_sleep);
void		print_status(t_philo *philo, const char *status);
void		pick_up_forks_even(t_philo *philo);
void		pick_up_forks_odd(t_philo *philo);

#endif
