/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samoreno <samoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:05:07 by samoreno          #+#    #+#             */
/*   Updated: 2022/04/27 10:15:02 by samoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	long long int	timestamp;
	int				death;
	pthread_mutex_t	pr_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	death_lock;
}	t_info;

typedef struct s_philo
{
	int				l_fork;
	int				r_fork;
	int				id_philo;
	long long int	last_eat;
	int				ate;
	pthread_mutex_t	*l_lock;
	pthread_mutex_t	*r_lock;
	t_info			*gen;
}	t_philo;

size_t			ft_strlen(const char *s);
int				ft_errors(int argc, char **argv);
t_info			ft_info(int argc, char **argv);
t_philo			*ft_philos(t_info *info);
int				ft_atoi(const char *str);
int				ft_threads(t_philo **philos);
void			*ft_routine(void *arg);
void			*ft_alive(t_philo *philos);
void			*ft_wait(int event, t_philo *philo);
void			ft_free_mutexs(t_philo **philos, pthread_mutex_t *locks);
pthread_mutex_t	*ft_mutexs(t_info *info);
void			ft_forks(t_philo *philos, pthread_mutex_t *locks);
long long int	ft_time_diff(struct timeval now, long long int og);
int				ft_pick_forks(t_philo *philo);
void			ft_drop_forks(t_philo *philo);
void			ft_join_threads(int threads, pthread_t *philos, void **retvals);
int				ft_filled(t_philo *philos);
int				ft_check_death(t_info *info);
#endif