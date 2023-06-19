/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syakovle <syakovle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:59:53 by syakovle          #+#    #+#             */
/*   Updated: 2023/06/17 17:06:34 by syakovle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include "../libft/libft.h"
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

# define MSG_ERR "Usage: ./philosophers <nbphilosophers> <timetodie> <timetoeat>\
 <timetosleep> <timeseating>\n"

typedef struct s_philo
{
	int				id;
	bool			lfork;
	bool			rfork;
	long int		countlunch;
	long int		time;
	struct s_philo	*pl;
	struct s_philo	*pr;
	struct s_table	*table;
	pthread_t		thread;
}	t_philo;

typedef struct s_table
{
	long int		timetoeat;
	long int		timetosleep;
	long int		timetodie;
	long int		hastoeat;
	long int		globaltime;
	int				numberphilo;
	bool			stopthread;
	pthread_t		thread;
	t_philo			*philo;
	pthread_mutex_t	mutexfork;
	pthread_mutex_t	mutexeat;
	pthread_mutex_t	mutexprint;
}	t_table;

int			ft_thread(t_table *table);
int			init(t_table *table, int ac, char **av);
long int	ft_gettime(void);
void		ft_eat(t_philo *philo);
void		setfork(t_philo *philo);
int			takefork(t_philo *philo);
void		ft_print(char *str, t_philo *philo);
int			inittable(t_table *table, int ac, char **av);
int			initmutex(t_table *table);

#endif