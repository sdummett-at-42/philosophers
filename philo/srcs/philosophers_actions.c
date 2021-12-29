/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 17:20:35 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:15:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_eating(t_philo *philo)
{
	if (print_timestamp(philo, EATING) < 0)
	{
		drop_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = gettime();
	pthread_mutex_unlock(&philo->last_meal_mutex);
	if (!(ft_msleep_wrapper(philo, philo->datas->time_to_eat)))
	{
		drop_forks(philo);
		return (0);
	}
	drop_forks(philo);
	return (1);
}

int	philo_has_eaten_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->time_must_eat_mutex);
	if (philo->time_must_eat > 0)
	{
		philo->time_must_eat = philo->time_must_eat - 1;
		if (philo->time_must_eat == 0)
		{
			pthread_mutex_unlock(&philo->time_must_eat_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->time_must_eat_mutex);
	return (0);
}

int	philo_is_sleeping(t_philo *philo)
{
	if (!print_timestamp(philo, SLEEPING))
		return (0);
	if (!(ft_msleep_wrapper(philo, philo->datas->time_to_sleep)))
		return (0);
	return (1);
}

int	philo_is_thinking(t_philo *philo)
{
	if (!print_timestamp(philo, THINKING))
		return (0);
	return (1);
}
