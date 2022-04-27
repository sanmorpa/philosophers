/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:52:19 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/27 11:17:10 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

static void	*ft_eat(t_philo *philo);
static void	*ft_sleep(t_philo *philo);

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		ft_wait(50, philo);
	while (ft_check_death(philo->gen) == 0)
	{
		ft_eat(philo);
		if (ft_check_death(philo->gen) == 1)
			return (NULL);
		ft_sleep(philo);
	}
	return (NULL);
}

static void	*ft_eat(t_philo *philo)
{
	struct timeval	eat;

	if (ft_pick_forks(philo) == 1)
		return (NULL);
	pthread_mutex_lock(&philo->gen->pr_lock);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (NULL);
	}
	gettimeofday(&eat, NULL);
	pthread_mutex_lock(&philo->gen->eat_lock);
	philo->last_eat = ft_time_diff(eat, philo->gen->timestamp);
	printf("[%lld] #%d is eating\n", philo->last_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->gen->eat_lock);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	ft_wait(philo->gen->t_eat, philo);
	ft_drop_forks(philo);
	pthread_mutex_lock(&philo->gen->eat_lock);
	philo->ate++;
	pthread_mutex_unlock(&philo->gen->eat_lock);
	return (NULL);
}

static void	*ft_sleep(t_philo *philo)
{
	struct timeval	sleep;
	struct timeval	think;

	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&sleep, NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (NULL);
	}
	printf("[%lld] #%d is sleeping\n",
		ft_time_diff(sleep, philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	ft_wait(philo->gen->t_sleep, philo);
	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&think, NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (NULL);
	}
	printf("[%lld] #%d is thinking\n",
		ft_time_diff(think, philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	return (NULL);
}
