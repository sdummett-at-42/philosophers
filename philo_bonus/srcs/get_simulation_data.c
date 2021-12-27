/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simulation_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 13:13:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	init_sem_name(t_philo *philo)
{
	philo->forks_name = string_generator();
	philo->someone_speak_name = string_generator();
	philo->someone_died_name = string_generator();
	philo->confirm_someone_died_name = string_generator();
}

void	get_simulation_data(t_philo *philo, char **args)
{
	philo->philo_number = ft_atoi(args[0]);
	philo->time_to_die = ft_atoi(args[1]);
	philo->time_to_eat = ft_atoi(args[2]);
	philo->time_to_sleep = ft_atoi(args[3]);
	if (args[4] != NULL)
		philo->time_must_eat = ft_atoi(args[4]);
	else
		philo->time_must_eat = -1;
	init_sem_name(philo);
	philo->forks_sem = sem_open(philo->forks_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)philo->philo_number);
	philo->someone_speak_sem = sem_open(philo->someone_speak_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)1);
	philo->someone_died_sem = sem_open(philo->someone_died_name, O_CREAT, S_IRUSR | S_IWUSR, (unsigned int)1);
	philo->pid = ft_calloc(philo->philo_number, sizeof(pid_t));
}
