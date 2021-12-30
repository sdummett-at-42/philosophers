/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:55:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 18:40:20 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_mutex);
	*(philo->datas->forks[philo->left_fork]) = NOT_TAKEN;
	pthread_mutex_unlock(philo->left_mutex);
}

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_mutex);
	*(philo->datas->forks[philo->right_fork]) = NOT_TAKEN;
	pthread_mutex_unlock(philo->right_mutex);
}

void	drop_forks(t_philo *philo)
{
	drop_left_fork(philo);
	drop_right_fork(philo);
}
