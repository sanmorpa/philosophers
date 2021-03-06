/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:49:05 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/13 10:39:59 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void				ft_fill(t_info *info, int iter, char *arg);

t_info	ft_info(int argc, char **argv)
{
	int		iter;
	t_info	info;

	iter = 1;
	while (iter < argc)
	{
		ft_fill(&info, iter, argv[iter]);
		iter++;
	}
	if (argc == 5)
		info.n_eat = -1;
	info.timestamp = 0LL;
	info.death = 0;
	return (info);
}

static void	ft_fill(t_info *info, int iter, char *arg)
{
	if (iter == 1)
		info->n_philo = ft_atoi(arg);
	if (iter == 2)
		info->t_die = ft_atoi(arg);
	if (iter == 3)
		info->t_eat = ft_atoi(arg);
	if (iter == 4)
		info->t_sleep = ft_atoi(arg);
	if (iter == 5)
		info->n_eat = ft_atoi(arg);
}

t_philo	*ft_philos(t_info *info)
{
	int		iter;
	t_philo	*philos;

	iter = 0;
	philos = malloc(sizeof(t_philo) * info->n_philo);
	if (!philos)
	{
		printf("Error: malloc allocation failed\n");
		return (NULL);
	}
	while (iter < info->n_philo)
	{
		philos[iter].gen = info;
		philos[iter].id_philo = iter + 1;
		philos[iter].last_eat = 0LL;
		philos[iter].ate = 0;
		iter++;
	}
	return (philos);
}

/*These functions allocate and fill all the necessary information:
An array of n structures t_philo that have individual philosopher information
and a pointer to a single t_info structure that has the shared info for all
philosphers */