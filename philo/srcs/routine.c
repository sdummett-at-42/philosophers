/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 10:42:34 by sdummett         ###   ########.fr       */
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
	while (true)
	{
		if (!philo_is_taking_forks(philo))
			break ;
		if (!philo_is_eating(philo))
			break ;
		if (!philo_is_sleeping(philo))
			break ;
		if (!philo_is_thinking(philo))
			break ;
	}
	pthread_join(monitor_thread, NULL);
	return (philo);
}

int	philo_is_taking_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->left_mutex);
	else
		pthread_mutex_lock(philo->right_mutex);
	if (!print_msg(philo, FORK_TAKEN))
	{
		if (philo->id % 2 == 0)
			pthread_mutex_unlock(philo->left_mutex);
		else
			pthread_mutex_unlock(philo->right_mutex);
		return (0);
	}
	if (!print_msg(philo, FORK_TAKEN))
	{
		drop_forks(philo);
		return (0);
	}
	return (1);
}

int	philo_is_eating(t_philo *philo)
{
	if (print_msg(philo, EATING) < 0)
	{
		drop_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	ft_usleep(philo->datas->time_to_eat);
	drop_forks(philo);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (1);
}

int	philo_is_sleeping(t_philo *philo)
{
	if (!print_msg(philo, SLEEPING))
		return (0);
	ft_usleep(philo->datas->time_to_sleep);
	return (1);
}

int	philo_is_thinking(t_philo *philo)
{
	if (!print_msg(philo, THINKING))
		return (0);
	return (1);
}
