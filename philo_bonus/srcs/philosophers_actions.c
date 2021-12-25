/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:20:35 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 11:29:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	philo_is_taking_forks(t_philo *philo)
{
	sem_wait(philo->forks_sem);
	if (!print_msg(philo, FORK_TAKEN))
	{
		sem_post(philo->forks_sem);
		return (0);
	}
	sem_wait(philo->forks_sem);
	if (!print_msg(philo, FORK_TAKEN))
	{
		sem_post(philo->forks_sem);
		sem_post(philo->forks_sem);
		return (0);
	}
	return (1);
}

int	philo_is_eating(t_philo *philo)
{
	if (print_msg(philo, EATING) < 0)
		return (0);
	// pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	ft_usleep(philo->datas->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
	// pthread_mutex_unlock(&philo->last_meal_mutex);
	return (1);
}

int	philo_has_eaten_enough(t_philo *philo)
{
	// pthread_mutex_lock(&philo->time_must_eat_mutex);
	if (philo->time_must_eat > 0)
	{
		philo->time_must_eat = philo->time_must_eat - 1;
		if (philo->time_must_eat == 0)
		{
			// pthread_mutex_unlock(&philo->time_must_eat_mutex);
			return (1);
		}
	}
	// pthread_mutex_unlock(&philo->time_must_eat_mutex);
	return (0);
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
