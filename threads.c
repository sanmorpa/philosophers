/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:49:21 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/28 17:07:10 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_create_threads(pthread_t *thr, t_philo *philos,
				void **retvals);

void	ft_threads(t_philo **philos)
{
	pthread_t		*threads;
	void			**retvals;
	int				n_threads;

	threads = malloc(sizeof(pthread_t) * philos[0]->gen->n_philo);
	retvals = malloc(sizeof(void *) * philos[0]->gen->n_philo);
	if (!threads || !retvals)
	{
		if (threads)
			free(threads);
		printf("Error: malloc allocation failed\n");
	}
	else
	{
		n_threads = ft_create_threads(threads, *philos, retvals);
		if (n_threads > 0)
		{
			ft_wait(philos[0]->gen->t_die, *philos);
			ft_alive(*philos);
			pthread_mutex_unlock(&philos[0]->gen->pr_lock);
			ft_join_threads(n_threads, threads, retvals);
		}
	}
}

static int	ft_create_threads(pthread_t *thr, t_philo *philos, void **retv)
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
			ft_join_threads(iter_th, &thr[iter_th], retv);
			return (-1);
		}
		iter_th++;
	}
	return (iter_th);
}

void	ft_join_threads(int threads, pthread_t *thr, void **retvals)
{
	int	iter_join;

	iter_join = 0;
	while (iter_join < threads)
	{
		if (pthread_join(thr[iter_join], &retvals[iter_join]) != 0)
		{
			printf("Error: Thread #%d hasn't been joined\n", iter_join);
			break ;
		}
		iter_join++;
	}
	free(thr);
	free(retvals);
}
