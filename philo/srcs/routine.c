/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 18:43:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	reaper_thread;
	pthread_t	eat_thread;

	philo = arg;
	// (void)reaper_thread;
	pthread_mutex_lock(&philo->datas->speak_mutex);
	pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
	if (philo->datas->all_philo_is_alived)
		printf("Hello from routine, I'm thread number %d\n", philo->id);
	pthread_mutex_unlock(&philo->datas->speak_mutex);
	pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
	
	// print_struct(philo->datas);
	pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
	while (philo->datas->all_philo_is_alived)
	{
		pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
		pthread_create(&reaper_thread, NULL, &reaper_routine, philo);
		pthread_create(&eat_thread, NULL, &eat_routine, philo);
		pthread_join(reaper_thread, NULL);
		pthread_join(eat_thread, NULL);
		pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
	}
	pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
	return (arg);
}
