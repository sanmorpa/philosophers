/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:52:19 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/14 09:34:35 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

static int	ft_eat(t_philo *philo);
static int	ft_sleep(t_philo *philo);

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id_philo % 2 == 0)
		ft_wait(50, philo);
	while (ft_check_death(philo->gen) == 0)
	{
		if (ft_eat(philo) == 1)
			return (NULL);
		if (ft_check_death(philo->gen) == 1)
			return (NULL);
		if (ft_sleep(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

static int	ft_eat(t_philo *philo)
{
	struct timeval	eat;

	if (ft_pick_forks(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&eat, NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (1);
	}
	pthread_mutex_lock(&philo->gen->eat_lock);
	philo->last_eat = ft_time_diff(eat, philo->gen->timestamp);
	pthread_mutex_unlock(&philo->gen->eat_lock);
	printf(GREEN "[%lld] #%d is eating\n", philo->last_eat, philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	pthread_mutex_lock(&philo->gen->eat_lock);
	philo->ate++;
	pthread_mutex_unlock(&philo->gen->eat_lock);
	ft_wait(philo->gen->t_eat, philo);
	ft_drop_forks(philo);
	return (0);
}

static int	ft_sleep(t_philo *philo)
{
	struct timeval	sleep;
	struct timeval	think;

	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&sleep, NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (1);
	}
	printf(YELLOW "[%lld] #%d is sleeping\n",
		ft_time_diff(sleep, philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	ft_wait(philo->gen->t_sleep, philo);
	pthread_mutex_lock(&philo->gen->pr_lock);
	gettimeofday(&think, NULL);
	if (ft_check_death(philo->gen) == 1)
	{
		pthread_mutex_unlock(&philo->gen->pr_lock);
		return (1);
	}
	printf(MAGENTA "[%lld] #%d is thinking\n",
		ft_time_diff(think, philo->gen->timestamp), philo->id_philo);
	pthread_mutex_unlock(&philo->gen->pr_lock);
	return (0);
}
