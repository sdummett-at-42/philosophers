/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:36:49 by sdummett         ###   ########.fr       */
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

# define NOT_TAKEN 0
# define TAKEN 1

typedef struct s_philo	t_philo;

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
	pthread_t		**philo_thread;
	t_philo			**philo;
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

/* check_args.c */
int				check_args(char **args);

/* check_if_someone_died.c */
bool			check_if_someone_died(t_philo *philo);

/* drop_forks.c */
void			drop_left_fork(t_philo *philo);
void			drop_right_fork(t_philo *philo);
void			drop_forks(t_philo *philo);

/* ft_atoi.c */
int				ft_atoi(const char *str);

/* ft_calloc.c */
void			*ft_calloc(size_t nmemb, size_t size);

/* ft_msleep_wrapper.c */
int				ft_msleep_wrapper(t_philo *philo, unsigned long time_to_sleep);

/* ft_msleep.c */
void			ft_msleep(unsigned long time_to_sleep);

/* ft_strerror.c */
void			ft_strerror(char *str);

/* ft_strlen.c */
int				ft_strlen(char *str);

/* gettime.c */
unsigned long	gettime(void);

/* init_simulation.c */
int				init_mutexes(t_datas *datas);
void			place_forks(t_philo *philo, t_datas *datas);
int				init_philos(t_datas *datas);
int				init_simulation(t_datas *datas, char **args);

/* philosophers_actions.c */
int				philo_is_eating(t_philo *philo);
int				philo_has_eaten_enough(t_philo *philo);
int				philo_is_sleeping(t_philo *philo);
int				philo_is_thinking(t_philo *philo);

/* is_number.c */
bool			is_number(char *arg);

/* init_simulation.c */
void			launch_threads(t_datas *datas);

/* monitor_routine.c */
bool			philo_died(t_philo *philo);
int				philo_ate_enough(t_philo *philo);
void			*monitor_routine(void *arg);
void			print_death_msg(t_philo *philo, unsigned long currtime);

/*
** philosophers_actions_on_forks.c
*/
int				philo_is_taking_forks(t_philo *philo);
int				try_take_left_forks(t_philo *philo);
int				take_left_fork(t_philo *philo);
int				try_take_right_fork(t_philo *philo);
int				take_right_fork(t_philo *philo);

/* philosopher_routine.c */
void			*philosopher_routine(void *arg);
void			init_philo_thread(t_philo *philo, pthread_t *monitor_thread);

/* philosophers_action_on_forks.c */
int				philo_is_taking_forks(t_philo *philo);
int				try_take_left_forks(t_philo *philo);
int				take_left_fork(t_philo *philo);
int				try_take_right_fork(t_philo *philo);
int				take_right_fork(t_philo *philo);

/* philosophers_action.c */
int				philo_is_eating(t_philo *philo);
int				philo_has_eaten_enough(t_philo *philo);
int				philo_is_sleeping(t_philo *philo);
int				philo_is_thinking(t_philo *philo);

/* print_timestamp.c */
int				print_timestamp(t_philo *philo, int state);

/* release_ressources.c */
void			destroy_mutexes(t_datas *datas);
void			release_ressources(t_datas *datas);

/* start_simulation.c */
void			start_simulation(t_datas *datas);

void			check_if_philo_died(t_philo *philo);
void			print_death_msg(t_philo *philo, unsigned long currtime);

/* wait_thread_end.c */
void			wait_threads_end(t_datas *datas);

#endif	
