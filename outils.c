/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:50:38 by samoreno          #+#    #+#             */
/*   Updated: 2022/07/13 10:51:04 by samoreno         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	int	i;
	int	negs;
	int	return_number;

	i = 0;
	negs = 0;
	return_number = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negs++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		return_number = (return_number * 10) + (str[i] - '0');
		i++;
	}
	if (negs)
		return_number *= -1;
	return (return_number);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
