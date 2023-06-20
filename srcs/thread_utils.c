/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:15:17 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/21 01:49:12 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_print(char *str, t_philo *philo)
{
	long int		gettime;

	pthread_mutex_lock(&philo->table->mutexprint);
	gettime = ft_gettime();
	if (philo->table->stopthread == true)
	{
		pthread_mutex_unlock(&philo->table->mutexprint);
		return ;
	}
	printf("%ld %d %s\n", gettime - philo->table->globaltime, philo->id, str);
	pthread_mutex_unlock(&philo->table->mutexprint);
}

int	takefork(t_philo *philo)
{
	if (philo->fork == false || philo->pl->fork == false)
		return (-1);
	philo->fork = false;
	philo->pl->fork = false;
	ft_print("has taken a fork\n", philo);
	ft_print("has taken a fork\n", philo);
	return (0);
}

void	setfork(t_philo *philo)
{
	philo->fork = true;
	philo->pl->fork = true;
	if (philo->table->stopthread == true)
		return ;
	ft_print("is sleeping\n", philo);
	usleep(philo->table->timetosleep * 1000);
	if (philo->table->stopthread == true)
		return ;
	ft_print("is thinking\n", philo);
}

void	ft_lock(t_philo *philo, int lock)
{
	if (lock == 0)
	{
		pthread_mutex_lock(&philo->mutexfork);
		pthread_mutex_lock(&philo->pl->mutexfork);
	}
	if (lock == 1)
	{
		pthread_mutex_unlock(&philo->mutexfork);
		pthread_mutex_unlock(&philo->pl->mutexfork);
	}
}

void	ft_eat(t_philo *philo)
{
	ft_lock(philo, 0);
	if (philo->table->stopthread == true || takefork(philo) == -1)
	{
		ft_lock(philo, 1);
		return ;
	}
	ft_lock(philo, 1);
	pthread_mutex_lock(&philo->table->mutexeat);
	philo->time = ft_gettime() - philo->table->globaltime;
	philo->countlunch += 1;
	ft_print("is eating\n", philo);
	pthread_mutex_unlock(&philo->table->mutexeat);
	usleep(philo->table->timetoeat * 1000);
	setfork(philo);
}
