/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 00:19:06 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/21 01:32:20 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <limits.h>

t_philo	*createlist(int id, t_table *table)
{
	t_philo	*list;

	list = malloc(sizeof(t_philo));
	if (list == NULL)
		return (NULL);
	list->id = id;
	list->fork = true;
	list->pl = NULL;
	list->pr = NULL;
	list->countlunch = 0;
	list->time = 0;
	list->thread = 0;
	list->table = table;
	if (pthread_mutex_init(&list->mutexfork, NULL) == -1)
	{
		free(list);
		return (NULL);
	}
	return (list);
}

t_philo	*addend(t_philo *list, int x, t_table *table)
{
	t_philo	*addedlist;
	t_philo	*newlist;

	addedlist = createlist(x, table);
	newlist = list;
	if (addedlist == NULL)
	{
		while (newlist != NULL)
		{
			newlist = list->pr;
			free(list);
			list = newlist;
		}
		return (NULL);
	}
	while (list->pr != NULL)
		list = list->pr;
	list->pr = addedlist;
	return (newlist);
}

void	ft_setleft(t_philo *philo)
{
	t_philo	*head;
	t_philo	*save;

	if (philo == NULL || philo->pr == NULL)
		return ;
	head = philo;
	while (philo->pr != NULL)
	{
		save = philo;
		philo = philo->pr;
		philo->pl = save;
	}
	philo->pr = head;
	philo->pl = save;
	head->pl = philo;
}

t_philo	*initphilo(t_philo *philo, int numberphilo, t_table *table)
{
	int		i;

	i = 1;
	philo = createlist(i, table);
	if (philo == NULL)
		return (NULL);
	while (i < numberphilo)
	{
		philo = addend(philo, i + 1, table);
		if (philo == NULL)
			return (NULL);
		i++;
	}
	ft_setleft(philo);
	return (philo);
}

int	init(t_table *table, int ac, char **av)
{
	if (initmutex(table) == -1)
		return (-1);
	if (inittable(table, ac, av) == -1)
		return (-1);
	table->philo = initphilo(table->philo, table->numberphilo, table);
	if (table->philo == NULL)
		return (-1);
	return (1);
}
