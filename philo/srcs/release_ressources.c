/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:32:22 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:22:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		pthread_mutex_destroy(datas->fork_mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&datas->someone_died_mutex);
	pthread_mutex_destroy(&datas->someone_speak_mutex);
}

void	release_ressources(t_datas *datas)
{
	int	i;

	i = 0;
	destroy_mutexes(datas);
	while (i < datas->philo_number)
	{
		free(datas->fork_mutex[i]);
		free(datas->forks[i]);
		free(datas->philo_thread[i]);
		pthread_mutex_destroy(&datas->philo[i]->last_meal_mutex);
		pthread_mutex_destroy(&datas->philo[i]->time_must_eat_mutex);
		free(datas->philo[i]);
		i++;
	}
	free(datas->fork_mutex);
	free(datas->forks);
	free(datas->philo_thread);
	free(datas->philo);
}
