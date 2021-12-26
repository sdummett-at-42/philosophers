/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 17:10:55 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <pthread.h>
# include <stdbool.h>
# include <fcntl.h>
# include <semaphore.h>
# include <errno.h>
# include "colorcodes.h"

# define THINKING 0
# define FORK_TAKEN 1
# define EATING 2
# define SLEEPING 3

typedef struct s_datas
{
	int				philo_number;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_must_eat;
	sem_t			*someone_speak_sem;
	sem_t			*someone_died_sem;
	sem_t			*forks_sem;
	char			*forks_name;
	char			*someone_died_name;
	char			*someone_speak_name;
	sem_t			*confirm_someone_died_sem;
	char			*confirm_someone_died_name;
	pid_t			**pid;
}	t_datas;

typedef struct s_philo
{
	int				id;
	int				time_must_eat;
	t_datas			*datas;
	unsigned long	last_meal;
	unsigned long	simulation_start;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	time_must_eat_mutex;
	sem_t			*forks_sem;
	sem_t			*someone_speak_sem;
	sem_t			*confirm_someone_died_sem;
	sem_t			*someone_died_sem;
	char			*confirm_someone_died_name;
}	t_philo;

/*
** philo_bonus/
*/
void			launch_processes(t_datas *datas, t_philo **philo);
void			process_routine(t_philo *philo);
void			wait_processes_end(t_datas *datas);
char			*ft_strdup(const char *str);

/*
** Utils
*/
int				ft_strlen(const char *str);
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

void			print_struct(t_datas *philo);

#endif	
