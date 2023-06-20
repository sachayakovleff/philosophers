/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:57:32 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/21 01:37:22 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	ft_overflow(char *arg)
{
	long long int	nb;

	nb = ft_atoi(arg);
	if (nb < 0 || nb > INT_MAX)
		return (-1);
	return (1);
}

void	checkargs(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isdigit(av[i]) == 0
			|| ft_strlen(av[i]) > 10 || ft_overflow(av[i]) == -1)
		{
			printf("Error: arg %d isn't digits or is too big\n", i);
			exit(0);
		}
		i++;
	}
}

void	ft_free(t_table table)
{
	t_philo	*save;
	int		i;

	i = 1;
	while (i <= table.numberphilo)
	{
		if (table.numberphilo > 1)
			save = table.philo->pr;
		pthread_mutex_destroy(&table.philo->mutexfork);
		free(table.philo);
		if (table.numberphilo > 1)
			table.philo = save;
		i++;
	}
	pthread_mutex_destroy(&table.mutexprint);
	pthread_mutex_destroy(&table.mutexeat);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (ac > 6 || ac < 5)
	{
		printf("%s", MSG_ERR);
		exit(0);
	}
	checkargs(ac, av);
	if (init(&table, ac, av) == -1)
	{
		printf("error in init.c, check with debugger\n");
		exit(0);
	}
	if (ft_thread(&table) == -1)
		printf("error while executing threads\n");
	ft_free(table);
	return (0);
}
