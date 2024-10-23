/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:31:43 by rhamini           #+#    #+#             */
/*   Updated: 2024/08/22 18:18:18 by rhamini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_pwd(void)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * 50);
	getcwd(s, 100);
	while (s[i])
		i++;
	ft_putstr(s);
	ft_putstr("/\n");
	free(s);
	s = NULL;
}

char	*prompt_begin(void)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(sizeof(char) * 50);
	getcwd(s, 100);
	while (s[i])
		i++;
	s[i] = '$';
	i++;
	s[i] = ' ';
	i++;
	s[i] = '\0';
	return (s);
}

void	my_scanf_string(char **str)
{
	char	*s;

	s = prompt_begin();
	*str = readline(s);
	if (*str == NULL)
	{
		ft_putstr("shell exit");
		free(s);
		exit(1);
	}
	free_tab(str);
	free(s);
}

int	main(void)
{
	char	*arg;

	while (1)
	{
		my_scanf_string(&arg);
		if (ft_strcmp(arg, "pwd") == 0)
			prompt_pwd();
		if (ft_strcmp(arg, "exit") == 0)
		{
			free(arg);
			break ;
		}
	}
	return (0);
}
