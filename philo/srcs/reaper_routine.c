/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:33:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 15:15:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*reaper_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	usleep(philo->datas->time_to_sleep);
	pthread_mutex_lock(&philo->has_eat_mutex);
	if (philo->has_eat == EAT)
	{
		pthread_mutex_unlock(&philo->has_eat_mutex);
		pthread_mutex_lock(philo->datas->speak_mutex);
		printf("REAPER: philo %d has eat :)\n", philo->id);
		pthread_mutex_unlock(philo->datas->speak_mutex);
		return (NULL);
	}
	else if (philo->has_eat == NOT_EAT)
	{
		philo->has_eat = DEAD;
		pthread_mutex_unlock(&philo->has_eat_mutex);
		pthread_mutex_lock(philo->datas->speak_mutex);
		//ft_putstr("💀 Philosopher has died\n");
		printf("REAPER : philo %d has died :(\n", philo->id);
		pthread_mutex_unlock(philo->datas->speak_mutex);
	}
	return (NULL);
}
