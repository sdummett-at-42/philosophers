/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:56:47 by sdummett         ###   ########.fr       */
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
# include <sys/types.h>
# include <signal.h>
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

# define FILENAME_LEN 125

typedef struct s_philo
{
	int				id;
	pid_t			*pid;
	int				philo_number;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_must_eat;
	pthread_mutex_t	time_must_eat_mutex;
	sem_t			*someone_speak_sem;
	sem_t			*forks_sem;
	char			*forks_name;
	sem_t			*someone_died_sem;
	char			*someone_died_name;
	char			*someone_speak_name;
	sem_t			*confirm_someone_died_sem;
	char			*confirm_someone_died_name;
	unsigned long	last_meal;
	pthread_mutex_t	last_meal_mutex;
	unsigned long	simulation_start;
	pthread_t		monitor_thread;
}	t_philo;

/* check_args.c */
int				check_args(char **args);

/* ft_atoi.c */
int				ft_atoi(const char *str);

/* ft_calloc.c */
void			*ft_calloc(size_t nmemb, size_t size);

/* ft_msleep.c */
void			ft_msleep(unsigned long time_to_sleep);

/* ft_rand.c */
unsigned int	ft_rand(unsigned int start_range, unsigned int end_range);

/* ft_strerror.c */
void			ft_strerror(char *str);

/* ft_strlen.c */
int				ft_strlen(const char *str);

/* gettime.c */
unsigned long	gettime(void);

/* init_simulation.c */
int				init_sem_name(t_philo *philo);
int				init_semaphores(t_philo *philo);
int				init_simulation(t_philo *philo, char **args);

/* is_number.c */
bool			is_number(char *arg);

/* launch_processes.c */
void			launch_processes(t_philo *philo);

/* monitor_routine.c */
void			*monitor_routine(void *arg);
int				check_if_philo_died(t_philo *philo);
void			print_death_msg(t_philo *philo, unsigned long currtime);

/* philosophers_actions.c */
int				philo_is_taking_forks(t_philo *philo);
int				philo_is_eating(t_philo *philo);
int				philo_has_eaten_enough(t_philo *philo);
int				philo_is_sleeping(t_philo *philo);
int				philo_is_thinking(t_philo *philo);

/* print_timestamp.c */
bool			check_someone_died(t_philo *philo);
int				print_timestamp(t_philo *philo, int state);

/* process_routine.c */
void			process_routine(t_philo *philo);
void			init_mutexes_and_semaphores(t_philo *philo);
void			release_subprocess_ressources(t_philo *philo);

/* release_ressources.c */
void			release_ressources(t_philo *philo);

/* start_simulation.c */
int				start_simulation(t_philo *philo, char **args);

/* string_generator.c */
char			*string_generator(void);

/* wait_processes_end.c */
void			wait_processes_end(t_philo *philo);

#endif	
