/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:47:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 11:23:49 by sdummett         ###   ########.fr       */
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
	printf(BMAG "Philo %d: %d <=|=> %d\n" RESET,
		philo->id, left_fork, right_fork);
}

t_philo	**init_philos(t_datas *datas)
{
	int		i;
	t_philo	**philo;

	philo = malloc(sizeof(t_philo *) * datas->philo_number);
	datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo[i] = malloc(sizeof(pthread_t));
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->datas = datas;
		place_forks(philo[i], datas);
		pthread_mutex_init(&philo[i]->last_meal_mutex, NULL);
		i++;
	}
	return (philo);
}
