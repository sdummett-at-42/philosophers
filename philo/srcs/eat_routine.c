/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:08:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 17:24:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	//usleep(100);
	pthread_mutex_lock(&philo->has_eat_mutex);
	if (philo->has_eat != DEAD)
	{
		philo->has_eat = EAT;
		pthread_mutex_lock(&philo->datas->speak_mutex);
		pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
		if (philo->datas->all_philo_is_alived)
			printf("EAT_ROUTINE : philo %d is eating\n", philo->id);
		pthread_mutex_unlock(&philo->has_eat_mutex);
		pthread_mutex_unlock(&philo->datas->speak_mutex);
		pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
		
		/*
		** Lock les fork mutexes -> usleep -> unlock les fork mutexes
		*/
		usleep(philo->datas->time_to_eat);
	}
	else
		pthread_mutex_unlock(&philo->has_eat_mutex);
	return (NULL);
}