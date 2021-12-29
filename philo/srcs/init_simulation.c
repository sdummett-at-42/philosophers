/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:27:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes(t_datas *datas)
{
	int	i;

	datas->fork_mutex = ft_calloc(datas->philo_number,
			sizeof(pthread_mutex_t *));
	if (datas->fork_mutex == NULL)
		return (0);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->fork_mutex[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (datas->fork_mutex[i] == NULL)
			return (0);
		pthread_mutex_init(datas->fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&datas->someone_died_mutex, NULL);
	pthread_mutex_init(&datas->someone_speak_mutex, NULL);
	return (1);
}

void	place_forks(t_philo *philo, t_datas *datas)
{
	int	tmp;
	int	right_fork;
	int	left_fork;

	if (philo->id == 0)
		right_fork = philo->datas->philo_number - 1;
	else
		right_fork = philo->id - 1;
	left_fork = philo->id;
	if (left_fork > right_fork)
	{
		tmp = left_fork;
		left_fork = right_fork;
		right_fork = tmp;
	}
	if (philo->id == 0 && left_fork < right_fork)
	{
		tmp = left_fork;
		left_fork = right_fork;
		right_fork = tmp;
	}
	philo->left_mutex = datas->fork_mutex[left_fork];
	philo->right_mutex = datas->fork_mutex[right_fork];
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

int	init_philos(t_datas *datas)
{
	int		i;

	datas->philo = ft_calloc(datas->philo_number, sizeof(t_philo *));
	datas->philo_thread = ft_calloc(datas->philo_number, sizeof(pthread_t *));
	if (datas->philo == NULL || datas->philo_thread == NULL)
		return (0);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo_thread[i] = ft_calloc(1, sizeof(pthread_t));
		datas->philo[i] = ft_calloc(1, sizeof(t_philo));
		if (datas->philo_thread[i] == NULL || datas->philo[i] == NULL)
			return (0);
		datas->philo[i]->id = i;
		datas->philo[i]->datas = datas;
		datas->philo[i]->time_must_eat = datas->time_must_eat;
		place_forks(datas->philo[i], datas);
		pthread_mutex_init(&datas->philo[i]->last_meal_mutex, NULL);
		pthread_mutex_init(&datas->philo[i]->time_must_eat_mutex, NULL);
		i++;
	}
	return (1);
}

int	init_simulation(t_datas *datas, char **args)
{
	int	i;

	datas->philo_number = ft_atoi(args[0]);
	datas->time_to_die = ft_atoi(args[1]);
	datas->time_to_eat = ft_atoi(args[2]);
	datas->time_to_sleep = ft_atoi(args[3]);
	if (args[4] != NULL)
		datas->time_must_eat = ft_atoi(args[4]);
	else
		datas->time_must_eat = -1;
	datas->someone_died = false;
	datas->forks = ft_calloc(datas->philo_number, sizeof(int *));
	if (datas->forks == NULL)
		return (0);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->forks[i] = ft_calloc(1, sizeof(int));
		if (datas->forks[i] == NULL)
			return (0);
		i++;
	}
	if (!init_mutexes(datas) || !init_philos(datas))
		return (0);
	return (1);
}
