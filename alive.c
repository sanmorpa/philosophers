/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:13:33 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/14 10:33:24 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print_death(t_philo *philo, int iter, int status);
static void	ft_unlock(t_philo *philos);
static int	ft_status(t_philo *philo, int iter);

void	ft_alive(t_philo *philos)
{
	int	status;
	int	iter;
	int	filled;

	status = 0;
	filled = 0;
	while (status == 0 && filled == 0)
	{
		iter = 0;
		while (iter < philos[0].gen->n_philo)
		{
			status = ft_status(philos, iter);
			filled = ft_filled(philos);
			if (status == 1 || filled == 1)
				break ;
			iter++;
		}
		usleep(1000);
	}
	pthread_mutex_lock(&philos[0].gen->death_lock);
	philos[0].gen->death = 1;
	pthread_mutex_unlock(&philos[0].gen->death_lock);
	ft_print_death(philos, iter, status);
	ft_unlock(philos);
}

static void	ft_unlock(t_philo *philos)
{
	int	iter;

	iter = 0;
	while (iter < philos[0].gen->n_philo)
	{
		pthread_mutex_unlock(philos[iter].l_lock);
		pthread_mutex_destroy(philos[iter].l_lock);
		iter++;
	}
}

int	ft_filled(t_philo *philos)
{
	int	iter;
	int	filled;

	iter = 0;
	filled = 0;
	if (philos[0].gen->n_eat == -1)
		return (0);
	while (iter < philos[0].gen->n_philo)
	{
		pthread_mutex_lock(&philos[0].gen->eat_lock);
		if (philos[iter].ate >= philos[iter].gen->n_eat)
			filled++;
		pthread_mutex_unlock(&philos[0].gen->eat_lock);
		iter++;
	}
	if (filled == philos[0].gen->n_philo)
	{
		pthread_mutex_lock(&philos[0].gen->pr_lock);
		return (1);
	}
	return (0);
}

static int	ft_status(t_philo *philo, int iter)
{
	struct timeval	now;

	pthread_mutex_lock(&philo->gen->eat_lock);
	gettimeofday(&now, NULL);
	if (ft_time_diff(now, philo[iter].gen->timestamp)
		<= (philo[iter].last_eat + philo[iter].gen->t_die))
	{
		pthread_mutex_unlock(&philo->gen->eat_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->gen->eat_lock);
	return (1);
}

static void	ft_print_death(t_philo *philo, int iter, int status)
{
	struct timeval	death;

	if (iter == philo[0].gen->n_philo)
		iter -= 1;
	gettimeofday(&death, NULL);
	if (status == 1)
	{
		pthread_mutex_lock(&philo[iter].gen->pr_lock);
		printf(RED "[%lld] #%d died\n", ft_time_diff(death,
				philo[iter].gen->timestamp), philo[iter].id_philo);
	}
	printf(WHITE);
	pthread_mutex_unlock(&philo[iter].gen->pr_lock);
}
