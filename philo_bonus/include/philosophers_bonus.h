/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 21:16:23 by sdummett         ###   ########.fr       */
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
	int				philo_number;
	int				id;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_must_eat;
	int				time_ate;
	sem_t			*someone_speak_sem;
	sem_t			*someone_died_sem;
	sem_t			*forks_sem;
	char			*forks_name;
	char			*someone_died_name;
	char			*someone_speak_name;
	sem_t			*confirm_someone_died_sem;
	char			*confirm_someone_died_name;
	unsigned long	last_meal;
	pid_t			*pid;
	unsigned long	simulation_start;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	time_ate_mutex;
	// sem_t			*forks_sem;
	// sem_t			*someone_speak_sem;
	// sem_t			*confirm_someone_died_sem;
	// sem_t			*someone_died_sem;
	// char			*confirm_someone_died_name;
}	t_philo;

/*
** philo_bonus/
*/
void			launch_processes(t_philo *philo);
void			process_routine(t_philo *philo);
void			wait_processes_end(t_philo *philo);
char			*ft_strdup(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*string_generator(void);
unsigned int 	ft_rand(unsigned int start_range, unsigned int end_range);

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
void			start_simulation(t_philo *philo, char **args);
void			get_simulation_data(t_philo *philo, char **args);
void			init_mutexes(t_philo *philo);
// t_philo			**init_philos(t_philo *philo);
// void			launch_threads(t_philo *philo, t_philo **philo);
void			wait_threads_end(t_philo *philo);
void			destroy_mutexes(t_philo *philo);
void			frees(t_philo *philo);
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

void			print_struct(t_philo *philo);

#endif	
