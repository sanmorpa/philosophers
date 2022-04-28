/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:09:55 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/27 10:30:30 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_info *info)
{
	pthread_mutex_lock(&info->death_lock);
	if (info->death == 0)
	{
		pthread_mutex_unlock(&info->death_lock);
		return (0);
	}
	pthread_mutex_unlock(&info->death_lock);
	return (1);
}
