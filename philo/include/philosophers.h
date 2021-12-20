/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/21 00:31:46 by sdummett         ###   ########.fr       */
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

# define DEAD -1
# define NOT_EAT 0
# define EAT 1

typedef struct s_datas
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	bool			all_philo_is_alived;
	pthread_mutex_t	all_philo_is_alived_mutex;
	int				**forks;
	pthread_t		**philo;
	pthread_mutex_t	**fork_mutex;
	pthread_mutex_t	speak_mutex;
	unsigned long int		simulation_start_ms;
}	t_datas;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;
	t_datas			*datas;
} t_philo;

void		ft_strerror(char *str);
int			ft_strlen(char *str);
bool		is_number(char *arg);
int			ft_atoi(const char *str);
void		ft_putstr(char *str);
int			check_args(char **args);
void		start_simulation(t_datas *datas, char **args);
void		get_simulation_data(t_datas *datas, char **args);
void		*routine(void *arg);
void		init_mutexes(t_datas *datas);
t_philo		**init_philos(t_datas *datas);
void		launch_threads(t_datas *datas, t_philo **philo);
void		wait_threads_end(t_datas *datas);
void		destroy_mutexes(t_datas *datas);
void		frees(t_datas *datas);
void		init_forks(t_datas *datas);
void		*reaper_routine(void *arg);
void		*eat_routine(void *arg);
void		unlock_has_eat_and_speak_and_philo_is_alived(t_philo *philo);
void		lock_speak_and_philo_is_alived(t_philo *philo);
unsigned long int	gettime(void);

/*
** Debug
*/
void	print_struct(t_datas *philo);

#endif	