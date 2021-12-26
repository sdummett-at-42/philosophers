/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:45:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 21:43:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	process_routine(t_philo *philo)
{
	pthread_t	monitor_thread;

	philo->forks_sem = sem_open(philo->forks_name, 0);
	if (philo->forks_sem == SEM_FAILED)
		printf("sem_open failed (forks)\n");
	philo->someone_speak_sem = sem_open(philo->someone_speak_name, 0);
	if (philo->someone_speak_sem == SEM_FAILED)
		printf("sem_open failed (mic)\n");
	philo->someone_died_sem = sem_open(philo->someone_died_name, 0);
	if (philo->someone_died_sem == SEM_FAILED)
		printf("sem_open failed (death)\n");
	pthread_mutex_init(&philo->time_ate_mutex, NULL);
	pthread_mutex_init(&philo->last_meal_mutex, NULL);
		// philo->simulation_start = gettime();
	while (gettime() < philo->simulation_start)
		ft_usleep(1);
	if (philo->id % 2)
		ft_usleep(10);
	pthread_create(&monitor_thread, NULL, &monitor_routine, philo);
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
	pthread_mutex_destroy(&philo->time_ate_mutex);
	pthread_mutex_destroy(&philo->last_meal_mutex);
	exit(0);
}
