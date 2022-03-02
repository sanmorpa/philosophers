/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:52:23 by samoreno          #+#    #+#             */
/*   Updated: 2022/02/11 10:26:04 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_print_lock(t_info *info);

pthread_mutex_t	*ft_mutexs(t_info *info)
{
	pthread_mutex_t	*mutexs;
	int				iter;

	iter = 0;
	if (ft_print_lock(info) == 1)
		return (NULL);
	mutexs = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!mutexs)
		return (NULL);
	while (iter < info->n_philo)
	{
		if (pthread_mutex_init(&mutexs[iter], NULL) != 0)
		{
			while (iter >= 0)
			{
				pthread_mutex_destroy(&mutexs[iter]);
				iter--;
			}
			printf("Error: mutex #%d hasn't been initalised\n", iter);
			free(mutexs);
			return (NULL);
		}
		iter++;
	}
	return (mutexs);
}

static int	ft_print_lock(t_info *info)
{
	if (pthread_mutex_init(&info->pr_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&info->pr_lock);
		printf("Error: mutex for printing hasn't been initialised\n");
		return (1);
	}
	return (0);
}

void	ft_free_mutexs(t_philo **philos, pthread_mutex_t *locks)
{
	int	iter;

	iter = 0;
	while (iter < philos[0]->gen->n_philo)
	{
		pthread_mutex_destroy(&locks[iter]);
		iter++;
	}
	free(locks);
}

void	ft_forks(t_philo *philos, pthread_mutex_t *locks)
{
	int		iter;

	iter = 0;
	while (iter < philos[0].gen->n_philo)
	{
		if (iter == philos[0].gen->n_philo - 1)
		{
			philos[iter].l_lock = &locks[iter];
			philos[iter].r_lock = &locks[0];
		}
		else
		{
			philos[iter].l_lock = &locks[iter];
			philos[iter].r_lock = &locks[iter + 1];
		}
		iter++;
	}
}
