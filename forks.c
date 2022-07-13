/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:51:49 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/13 12:31:53 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_pick_forks(t_philo *philo)
{
	struct timeval	picks[2];

	pthread_mutex_lock(philo->l_lock);
	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&picks[0], NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (1);
	}
	printf(BLUE "[%lld] #%d has taken a fork\n",
		ft_time_diff(picks[0], philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	pthread_mutex_lock(philo->r_lock);
	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&picks[1], NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (1);
	}
	printf(BLUE "[%lld] #%d has taken a fork\n",
		ft_time_diff(picks[1], philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	return (0);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_lock);
	pthread_mutex_unlock(philo->l_lock);
}
