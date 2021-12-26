/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 15:08:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include "colorcodes.h"

# define THINKING 0
# define FORK_TAKEN 1
# define EATING 2
# define SLEEPING 3

typedef struct s_datas
{
	int				philo_number;
	int				**forks;
	bool			someone_died;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_must_eat;
	unsigned long	simulation_start;
	pthread_t		**philo;
	pthread_mutex_t	**fork_mutex;
	pthread_mutex_t	someone_died_mutex;
	pthread_mutex_t	someone_speak_mutex;
}	t_datas;

typedef struct s_philo
{
	int				id;
	int				time_must_eat;
	int				left_fork;
	int				right_fork;
	t_datas			*datas;
	pthread_mutex_t	last_meal_mutex;
	unsigned long	last_meal;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	pthread_mutex_t	time_must_eat_mutex;
}	t_philo;

/*
** Utils
*/
int				ft_strlen(char *str);
int				ft_atoi(const char *str);
bool			is_number(char *arg);
void			ft_putstr(char *str);
void			ft_strerror(char *str);
void			ft_usleep(unsigned long time_to_sleep);
unsigned long	gettime(void);

int				check_args(char **args);
void			start_simulation(t_datas *datas, char **args);
void			get_simulation_data(t_datas *datas, char **args);
void			init_mutexes(t_datas *datas);
t_philo			**init_philos(t_datas *datas);
void			launch_threads(t_datas *datas, t_philo **philo);
void			wait_threads_end(t_datas *datas);
void			destroy_mutexes(t_datas *datas);
void			frees(t_datas *datas);
void			unlock_has_eat_and_speak_and_philo_is_alived(t_philo *philo);
int				print_msg(t_philo *philo, int state);
void			drop_forks(t_philo *philo);

/*
** routine.c
*/
void			*routine(void *arg);
int				philo_is_eating(t_philo *philo);
int				philo_has_eaten_enough(t_philo *philo);
int				philo_is_sleeping(t_philo *philo);
int				philo_is_thinking(t_philo *philo);
int				philo_is_taking_forks(t_philo *philo);

/*
** monitor_routine.c
*/
void			*monitor_routine(void *arg);
void			check_if_philo_died(t_philo *philo);
void			print_death_msg(t_philo *philo, unsigned long currtime);

/*
** Debug
*/
void			print_struct(t_datas *philo);

#endif	
