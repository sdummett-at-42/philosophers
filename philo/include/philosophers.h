/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 21:41:05 by sdummett         ###   ########.fr       */
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

typedef struct s_philo
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
	int				**forks;
	pthread_t		**philo;
	pthread_mutex_t	**fork_mutex;

}	t_philo;

void	ft_strerror(char *str);
int		ft_strlen(char *str);
bool	is_number(char *arg);
int		ft_atoi(const char *str);
int		check_args(char **args);
void	start_simulation(t_philo *philo, char **args);
void	get_simulation_data(t_philo *philo, char **args);

/*
** Debug
*/
void	print_struct(t_philo *philo);

#endif