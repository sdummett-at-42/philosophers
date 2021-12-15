/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 16:17:21 by sdummett         ###   ########.fr       */
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
	printf("Hello from routine, I'm thread number %d\n", philo->id);
	pthread_mutex_unlock(&philo->datas->speak_mutex);
	// print_struct(philo->datas);
	while (philo->datas->all_philo_is_alived)
	{
		pthread_create(&reaper_thread, NULL, &reaper_routine, philo);
		pthread_create(&eat_thread, NULL, &eat_routine, philo);
		pthread_join(reaper_thread, NULL);
		pthread_join(eat_thread, NULL);
	}
	return (arg);
}
