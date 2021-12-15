/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:33:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:56:57 by sdummett         ###   ########.fr       */
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
		return NULL;
	else if (philo->has_eat == NOT_EAT)
	{
		pthread_mutex_lock(philo->datas->speak_mutex);
		ft_putstr("Philosopher has died\n");
		pthread_mutex_unlock(philo->datas->speak_mutex);
		philo->has_eat = DEAD;
	}
	pthread_mutex_unlock(&philo->has_eat_mutex);
	return (NULL);
}