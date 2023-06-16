/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 02:28:07 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/16 02:29:21 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	initmutex(t_table *table)
{
	if (pthread_mutex_init(&table->mutexeat, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&table->mutexfork, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&table->mutexprint, NULL) == -1)
		return (-1);
	return (1);
}

int	inittable(t_table *table, int ac, char **av)
{
	table->numberphilo = ft_atoi(av[1]);
	table->timetodie = ft_atoi(av[2]);
	table->timetoeat = ft_atoi(av[3]);
	table->timetosleep = ft_atoi(av[4]);
	table->stopthread = false;
	if (ac == 6)
		table->hastoeat = ft_atoi(av[5]);
	else
		table->hastoeat = -1;
	if (table->numberphilo <= 0)
		return (printf("Error, need at least 1 philosopher\n"), -1);
	return (1);
}