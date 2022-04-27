/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:49:05 by samoreno          #+#    #+#             */
/*   Updated: 2022/02/16 11:09:52 by samoreno         ###   ########.fr       */
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
		return (NULL);
	while (iter < info->n_philo)
	{
		philos[iter].gen = info;
		philos[iter].id_philo = iter + 1;
		philos[iter].last_eat = 0LL;
		philos[iter].ate = 0;
		philos[iter].l_fork = iter;
		if (iter == info->n_philo - 1)
			philos[iter].r_fork = 0;
		else
			philos[iter].r_fork = iter + 1;
		iter++;
	}
	return (philos);
}
