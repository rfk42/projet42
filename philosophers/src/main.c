/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 16:31:17 by rhamini           #+#    #+#             */
/*   Updated: 2024/12/31 14:15:22 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	validate_arguments(char **av)
{
	int			i;
	long int	value;

	i = 1;
	while (av[i])
	{
		value = ft_atol(av[i]);
		if (!is_valid_number(av[i]) || value > 2147483647 || (i == 1
				&& value > 200) || value == 0)
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_simulation	simulation;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	if (validate_arguments(av))
		return (2);
	initialize_simulation_parameters(&simulation, ac, av);
	initialize_simulation(&simulation, simulation.die_time_limit,
		simulation.eat_duration, simulation.sleep_duration);
	create_philo_threads(&simulation, simulation.total_philosophers);
	monitor_philosophers(&simulation);
	join_philo_threads(&simulation, simulation.total_philosophers);
	destroy_simulation(&simulation);
	return (0);
}
