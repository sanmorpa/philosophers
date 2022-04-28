/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:48:56 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/28 17:23:36 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_info			info;
	pthread_mutex_t	*locks;

	if (ft_errors(argc, argv) == 0)
	{
		info = ft_info(argc, argv);
		philos = ft_philos(&info);
		if (!philos)
			return (1);
		locks = ft_mutexs(&info);
		if (!locks)
		{
			free(philos);
			return (1);
		}
		ft_forks(philos, locks);
		ft_threads(&philos);
		ft_destroy_mutex(philos[0].gen->n_philo, locks, &info);
		free(philos);
	}
	return (0);
}
