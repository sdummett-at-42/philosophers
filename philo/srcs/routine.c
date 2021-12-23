/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/23 18:45:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo				*philo;
	pthread_t			monitor_thread;

	philo = arg;
	
	pthread_create(&monitor_thread, NULL, &monitor_routine, philo);
	//while (gettime() < philo->datas->simulation_start_ms);
	philo->simulation_start = gettime();
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	while (true)
	{
		
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
		ft_usleep(philo->datas->time_to_eat);
		drop_forks(philo);
		pthread_mutex_unlock(&philo->last_meal_mutex);
		if (print_msg(philo, SLEEPING) < 0)
			break ;
		ft_usleep(philo->datas->time_to_sleep);
		if (print_msg(philo, THINKING) < 0)
			break ;
	}
	pthread_join(monitor_thread, NULL);
	return (NULL);
}
