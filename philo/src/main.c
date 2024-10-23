/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:39:48 by rhamini           #+#    #+#             */
/*   Updated: 2024/10/23 17:39:48 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc != 5 && argc != 6)
	{
		printf("invalid argument\n");
		return (1);
	}
	parsing(argv);
	program.num_philos = ft_long_atoi(argv[1]);
	program.time_to_die = ft_long_atoi(argv[2]) * 1000;
	program.time_to_eat = ft_long_atoi(argv[3]) * 1000;
	program.time_to_sleep = ft_long_atoi(argv[4]) * 1000;
	if (argc == 6)
		program.nb_must_eat = ft_long_atoi(argv[5]);
	else
		program.nb_must_eat = -1;
	initialize_program(&program, program.time_to_die, program.time_to_eat,
		program.time_to_sleep);
	create_philo_threads(&program, program.num_philos);
	monitor_philos(&program);
	join_philo_threads(&program, program.num_philos);
	destroy_program(&program);
	return (0);
}
