/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/20 18:47:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	lock_speak_and_philo_is_alived(philo);
	if (philo->datas->all_philo_is_alived)
		printf("Hello from routine, I'm thread number %d\n", philo->id);
	pthread_mutex_unlock(&philo->datas->speak_mutex);
	pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
	pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
	while (philo->datas->all_philo_is_alived)
	{
		usleep(philo->datas->time_to_sleep);
		// pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
		// pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
		break ;
	}
	pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
	return (arg);
}
