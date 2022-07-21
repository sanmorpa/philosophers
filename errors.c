/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:48:47 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/13 10:34:55 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_integer(char *arg);

int	ft_errors(int argc, char **argv)
{
	int	iter;

	iter = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Error: Incorrect number of arguments\n");
		return (1);
	}
	while (iter < argc)
	{
		if (ft_integer(argv[iter]) == 1)
		{
			printf("Error: Incorrect input\n");
			return (1);
		}
		iter++;
	}
	return (0);
}

static int	ft_integer(char *arg)
{
	int	iter;

	iter = 0;
	while (arg[iter])
	{
		if (ft_strlen(arg) == 1 && arg[iter] == '0')
			return (1);
		if (arg[iter] < 48 || arg[iter] > 57)
			return (1);
		iter++;
	}
	return (0);
}
