/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 14:56:46 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	reaper_thread;

	philo = arg;
	// (void)reaper_thread;
	pthread_mutex_lock(philo->datas->speak_mutex);
	printf("Hello from routine, I'm thread number %d\n", philo->id);
	pthread_mutex_unlock(philo->datas->speak_mutex);
	// qprint_struct(philo->datas);
	pthread_create(&reaper_thread, NULL, &reaper_routine, philo);
	pthread_join(reaper_thread, NULL);
	return (arg);
}
