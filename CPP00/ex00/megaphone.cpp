/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:05:57 by rhamini           #+#    #+#             */
/*   Updated: 2025/02/09 12:54:54 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void	ft_argupcase(char **arg)
{
	int i = 0, a = 1;
	
	while (arg[a])
	{
		i = 0;
		while (arg[a][i])
		{	
			std::cout.put(islower(arg[a][i]) ? toupper(arg[a][i]) : arg[a][i]);
			i++;
		}
		a++;
		std::cout.put(arg[a] ? ' ' : '\n');
	}
}

int main(int ac, char **av)
{
	if (ac >= 2)
		ft_argupcase(av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
