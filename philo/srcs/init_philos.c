/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:47:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:47:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	place_forks(t_philo *philo, t_datas *datas)
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

void	init_philos(t_datas *datas)
{
	int		i;

	datas->philo = ft_calloc(datas->philo_number, sizeof(t_philo *));
	datas->philo_thread = ft_calloc(datas->philo_number, sizeof(pthread_t *));
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo_thread[i] = ft_calloc(1, sizeof(pthread_t));
		datas->philo[i] = ft_calloc(1, sizeof(t_philo));
		datas->philo[i]->id = i;
		datas->philo[i]->datas = datas;
		datas->philo[i]->time_must_eat = datas->time_must_eat;
		place_forks(datas->philo[i], datas);
		pthread_mutex_init(&datas->philo[i]->last_meal_mutex, NULL);
		pthread_mutex_init(&datas->philo[i]->time_must_eat_mutex, NULL);
		i++;
	}
}
