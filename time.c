/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:35:51 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/27 12:06:46 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int	ft_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000LL + now.tv_usec / 1000);
}

long long int	ft_time_diff(struct timeval now, long long int og)
{
	long long int	diff;

	diff = now.tv_sec * 1000LL + now.tv_usec / 1000 - og;
	return (diff);
}

void	*ft_wait(int event, t_philo *philo)
{
	long long int	og;
	long long int	act;
	struct timeval	now;

	gettimeofday(&now, NULL);
	og = now.tv_sec * 1000LL + now.tv_usec / 1000;
	act = now.tv_sec * 1000LL + now.tv_usec / 1000;
	while (act - og < event)
	{
		if (ft_check_death(philo->gen) == 1)
			return (NULL);
		act = ft_time();
		usleep(200);
	}
	return (NULL);
}
