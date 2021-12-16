/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:33:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/16 08:58:16 by sdummett         ###   ########.fr       */
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
		philo->has_eat = NOT_EAT;
		lock_speak_and_philo_is_alived(philo);
		if (philo->datas->all_philo_is_alived)
			printf("REAPER : philo %d has eat\n", philo->id);
		unlock_has_eat_and_speak_and_philo_is_alived(philo);
	}
	else if (philo->has_eat == NOT_EAT)
	{
		lock_speak_and_philo_is_alived(philo);
		if (philo->datas->all_philo_is_alived)
		{
			philo->datas->all_philo_is_alived = false;
			philo->has_eat = DEAD;
			
			printf("REAPER : philo %d has died :(\n", philo->id);
			unlock_has_eat_and_speak_and_philo_is_alived(philo);
		}
		else
			unlock_has_eat_and_speak_and_philo_is_alived(philo);
	}
	return (NULL);
}
