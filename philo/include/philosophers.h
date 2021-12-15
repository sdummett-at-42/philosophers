/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 14:18:54 by sdummett         ###   ########.fr       */
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
	int				**forks;
	pthread_t		**philo;
	pthread_mutex_t	**fork_mutex;
	pthread_mutex_t	*speak_mutex;
}	t_datas;

typedef struct s_philo
{
	int				id;
	int				has_eat;
	pthread_mutex_t	has_eat_mutex;
	t_datas			*datas;
} t_philo;

void	ft_strerror(char *str);
int		ft_strlen(char *str);
bool	is_number(char *arg);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
int		check_args(char **args);
void	start_simulation(t_datas *philo, char **args);
void	get_simulation_data(t_datas *philo, char **args);
void	*routine(void *arg);
void	init_mutexes(t_datas *philo);
void	launch_threads(t_datas *philo);
void	wait_threads_end(t_datas *philo);
void	destroy_mutexes(t_datas *philo);
void	frees(t_datas *philo);
void	init_forks(t_datas *philo);
void	*reaper_routine(void *arg);

/*
** Debug
*/
void	print_struct(t_datas *philo);

#endif	