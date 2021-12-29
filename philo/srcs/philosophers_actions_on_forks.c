/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_actions_on_forks.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:05:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:15:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_is_taking_forks(t_philo *philo)
{
	while (true)
	{
		if (try_take_left_forks(philo))
		{
			if (!(take_left_fork(philo)))
				return (0);
			else if (try_take_right_fork(philo))
			{
				if (!(take_right_fork(philo)))
					return (0);
				else
					return (1);
			}
		}
	}
}

int	try_take_left_forks(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(philo->left_mutex);
		if (*(philo->datas->forks[philo->left_fork]) == TAKEN)
		{
			pthread_mutex_unlock(philo->left_mutex);
			ft_msleep(1);
		}
		else
			break ;
	}
	return (1);
}

int	take_left_fork(t_philo *philo)
{
	*(philo->datas->forks[philo->left_fork]) = TAKEN;
	pthread_mutex_unlock(philo->left_mutex);
	if (!print_timestamp(philo, FORK_TAKEN))
	{
		drop_left_fork(philo);
		return (0);
	}
	return (1);
}

int	try_take_right_fork(t_philo *philo)
{
	while (true)
	{
		pthread_mutex_lock(philo->right_mutex);
		if (*(philo->datas->forks[philo->right_fork]) == TAKEN)
		{
			pthread_mutex_unlock(philo->right_mutex);
			ft_msleep(1);
		}
		else
			break ;
	}
	return (1);
}

int	take_right_fork(t_philo *philo)
{
	*(philo->datas->forks[philo->right_fork]) = TAKEN;
	pthread_mutex_unlock(philo->right_mutex);
	if (!print_timestamp(philo, FORK_TAKEN))
	{
		drop_forks(philo);
		return (0);
	}
	return (1);
}
