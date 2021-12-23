/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/23 15:34:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo				*philo;
	pthread_t			monitor_thread;

	philo = arg;
	
	pthread_create(&monitor_thread, NULL, &monitor_routine, philo);
	while (gettime() < philo->datas->simulation_start_ms);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	while (true)
	{
		if (print_msg(philo, THINKING) < 0)
			break ;
		pthread_mutex_lock(philo->left_mutex);
		if (print_msg(philo, FORK_TAKEN) < 0)
		{
			pthread_mutex_unlock(philo->left_mutex);
			break ;
		}
		pthread_mutex_lock(philo->right_mutex);
		if (print_msg(philo, FORK_TAKEN) < 0)
		{
			drop_forks(philo);
			break ;
		}
		if (print_msg(philo, EATING) < 0)
		{
			drop_forks(philo);
			break ;
		}
		pthread_mutex_lock(&philo->last_meal_mutex);
		philo->last_meal = gettime();
		usleep(philo->datas->time_to_eat * 1000);
		drop_forks(philo);

		pthread_mutex_unlock(&philo->last_meal_mutex);
		if (print_msg(philo, SLEEPING) < 0)
			break ;
		usleep(philo->datas->time_to_sleep * 1000);
	}
	pthread_join(monitor_thread, NULL);
	return (NULL);
}

		// if ((gettime() - start) >= (unsigned long int)philo->datas->time_to_die)
		// {
		// 	pthread_mutex_lock(&philo->datas->someone_died_mutex);
		// 	philo->datas->someone_died = true;
		// 	pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		// 	current_time = gettime() - philo->datas->simulation_start_ms;
		// 	printf( BRED "%-6ld %-2d died\n" RESET, current_time, philo->id);
		// 	drop_forks(philo);
		// 	break ;
		// }