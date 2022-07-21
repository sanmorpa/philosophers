/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:49:21 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/14 09:33:42 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_create_threads(pthread_t *thr, t_philo *philos);

void	ft_threads(t_philo **philos, pthread_mutex_t *locks)
{
	pthread_t		*threads;
	int				n_threads;

	threads = malloc(sizeof(pthread_t) * philos[0]->gen->n_philo);
	if (!threads)
		printf("Error: malloc allocation failed\n");
	else
	{
		n_threads = ft_create_threads(threads, *philos);
		if (n_threads > 0)
		{
			usleep(philos[0]->gen->t_die);
			ft_alive(*philos);
			ft_join_threads(n_threads, threads);
		}
	}
	ft_destroy_mutex(-1, locks, philos[0]->gen);
	free(*philos);
}

static int	ft_create_threads(pthread_t *thr, t_philo *philos)
{
	int				iter_th;
	struct timeval	init_t;

	iter_th = 0;
	gettimeofday(&init_t, NULL);
	philos[0].gen->timestamp = init_t.tv_usec / 1000 + init_t.tv_sec * 1000LL;
	while (iter_th < (philos[0].gen->n_philo))
	{
		if (pthread_create(&thr[iter_th], NULL, ft_routine,
				(void *)&philos[iter_th]) != 0)
		{
			printf("Error: thread #%d hasn't been created\n", iter_th);
			ft_join_threads(iter_th, &thr[iter_th]);
			return (-1);
		}
		iter_th++;
	}
	return (iter_th);
}

void	ft_join_threads(int threads, pthread_t *thr)
{
	int	iter_join;

	iter_join = 0;
	while (iter_join < threads)
	{
		if (pthread_join(thr[iter_join], NULL) != 0)
		{
			printf("Error: Thread #%d hasn't been joined\n", iter_join);
			break ;
		}
		iter_join++;
	}
	free(thr);
}
