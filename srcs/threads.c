/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 03:07:46 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/19 16:38:18 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_alllaunched(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->table->hastoeat == -1)
		return (-1);
	while (i < philo->table->numberphilo)
	{
		if (philo->countlunch < philo->table->hastoeat)
			return (-1);
		if (philo->table->numberphilo != 1)
			philo = philo->pr;
		i++;
	}
	return (1);
}

void	*routine(void *args)
{
	t_philo		*philo;

	philo = (t_philo *) args;
	philo->time = ft_gettime() - philo->table->globaltime;
	if (philo->id % 2 == 0 && philo->table->timetodie > 0)
		usleep(500);
	while (philo->table->stopthread == false)
	{
		if (ft_alllaunched(philo) == 1)
		{
			philo->table->stopthread = true;
			break ;
		}
		if (philo->table->numberphilo != 1)
			ft_eat(philo);
	}
	printf("philo %d lunched %ld times \n", philo->id, philo->countlunch);
	pthread_exit(NULL);
}

void	*checker(void *args)
{
	t_philo	*philo;

	philo = (t_philo *) args;
	while (philo->table->stopthread == false)
	{
		if (ft_gettime() - philo->table->globaltime - philo->time
			> philo->table->timetodie)
		{
			pthread_mutex_lock(&philo->table->mutexprint);
			if (ft_gettime() - philo->table->globaltime - philo->time
				> philo->table->timetodie)
			{
				printf("%ld %d ", ft_gettime()
					- philo->table->globaltime, philo->id);
				printf("is dead\n");
				philo->table->stopthread = true;
			}
			pthread_mutex_unlock(&philo->table->mutexprint);
		}
		if (philo->table->numberphilo > 1)
			philo = philo->pr;
	}
	pthread_exit(NULL);
}

int	ft_thread(t_table *table)
{
	int	i;

	i = 0;
	table->globaltime = ft_gettime();
	pthread_create(&table->thread, NULL, checker, table->philo);
	while (i < table->numberphilo)
	{
		table->philo->time = ft_gettime();
		table->philo->table = table;
		if (pthread_create(&table->philo->thread, NULL, routine, table->philo))
			return (-1);
		if (table->numberphilo > 1)
			table->philo = table->philo->pr;
		i++;
	}
	i = 0;
	pthread_join(table->thread, NULL);
	while (i < table->numberphilo)
	{
		pthread_join(table->philo->thread, NULL);
		if (table->numberphilo > 1)
		table->philo = table->philo->pr;
		i++;
	}
	return (0);
}
