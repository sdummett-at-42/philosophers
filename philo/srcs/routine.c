/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 17:20:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo				*philo;
	pthread_t			monitor_thread;

	philo = arg;
	pthread_create(&monitor_thread, NULL, &monitor_routine, philo);
	philo->simulation_start = gettime();
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	while (true && philo->time_must_eat != 0)
	{
		if (!philo_is_taking_forks(philo))
			break ;
		if (!philo_is_eating(philo))
			break ;
		if (philo_has_eaten_enough(philo))
			break ;
		if (!philo_is_sleeping(philo))
			break ;
		if (!philo_is_thinking(philo))
			break ;
	}
	pthread_join(monitor_thread, NULL);
	return (philo);
}
