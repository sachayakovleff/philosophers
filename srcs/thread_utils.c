/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 04:15:17 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/16 03:03:15 by syakovle         ###   ########.fr       */
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

void	takefork(t_philo *philo)
{
	philo->lfork = false;
	philo->rfork = false;
	philo->pl->rfork = false;
	philo->pr->lfork = false;
	ft_print("has taken a fork\n", philo);
	ft_print("has taken a fork\n", philo);
}

void	setfork(t_philo *philo)
{
	philo->lfork = true;
	philo->rfork = true;
	philo->pl->rfork = true;
	philo->pr->lfork = true;
	if (philo->table->stopthread == true)
		return ;
	ft_print("is sleeping\n", philo);
	usleep(philo->table->timetosleep * 1000);
	if (philo->table->stopthread == true)
		return ;
	ft_print("is thinking\n", philo);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mutexfork);
	if (philo->table->stopthread == true)
	{
		pthread_mutex_unlock(&philo->table->mutexfork);
		return ;
	}
	takefork(philo);
	pthread_mutex_unlock(&philo->table->mutexfork);
	pthread_mutex_lock(&philo->table->mutexeat);
	philo->time = ft_gettime() - philo->table->globaltime;
	philo->countlunch += 1;
	ft_print("is eating\n", philo);
	pthread_mutex_unlock(&philo->table->mutexeat);
	usleep(philo->table->timetoeat * 1000);
	setfork(philo);
}
