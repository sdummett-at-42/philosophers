/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:45:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 20:20:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	process_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	philo->forks_sem = sem_open("forks", 0);
	if (philo->forks_sem == SEM_FAILED)
		printf("sem_open failed (forks)\n");
	philo->someone_speak_sem = sem_open("mic", 0);
	if (philo->someone_speak_sem == SEM_FAILED)
		printf("sem_open failed (mic)\n");
	philo->someone_died_sem = sem_open("death", 0);
	if (philo->someone_died_sem == SEM_FAILED)
		printf("sem_open failed (death)\n");
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
	sem_close(philo->forks_sem);
	sem_close(philo->someone_speak_sem);
	exit(0);
}