/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 18:03:26 by sdummett         ###   ########.fr       */
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

/*
** philo_bonus/
*/
void			launch_processes(t_philo *philo);
void			wait_processes_end(t_philo *philo);
char			*ft_strdup(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*string_generator(void);
unsigned int	ft_rand(unsigned int start_range, unsigned int end_range);
int				init_simulation(t_philo *philo, char **args);
void			release_ressources(t_philo *philo);

/*
** process_routine.c
*/
void			process_routine(t_philo *philo);
void			release_subprocess_ressources(t_philo *philo);
void			init_mutexes_and_semaphores(t_philo *philo);

/*
** process_routine.c
*/
void			*monitor_routine(void *arg);
int				check_if_philo_died(t_philo *philo);
void			print_death_msg(t_philo *philo, unsigned long currtime);

/*
** Utils
*/
int				ft_atoi(const char *str);
bool			is_number(char *arg);
void			ft_putstr(char *str);
void			ft_strerror(char *str);
int				ft_strlen(const char *str);
void			ft_msleep(unsigned long time_to_sleep);
unsigned long	gettime(void);
int				check_args(char **args);
int				start_simulation(t_philo *philo, char **args);
void			wait_threads_end(t_philo *philo);
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

#endif	
