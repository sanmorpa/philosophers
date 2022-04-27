/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:48:56 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/27 12:22:05 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int				status;
	t_philo			*philos;
	t_info			info;
	pthread_mutex_t	*locks;

	if (ft_errors(argc, argv) == 0)
	{
		info = ft_info(argc, argv);
		philos = ft_philos(&info);
		if (philos == NULL)
			return (1);
		locks = ft_mutexs(&info);
		if (!locks)
		{
			free(philos);
			return (1);
		}
		ft_forks(philos, locks);
		status = ft_threads(&philos);
		ft_free_mutexs(&philos, locks);
		free(philos);
	}
	return (0);
}
