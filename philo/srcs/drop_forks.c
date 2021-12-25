/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:55:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 15:58:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_mutex);
	*(philo->datas->forks[philo->left_fork]) = 0;
	pthread_mutex_unlock(philo->left_mutex);
	pthread_mutex_lock(philo->right_mutex);
	*(philo->datas->forks[philo->right_fork]) = 0;
	pthread_mutex_unlock(philo->right_mutex);
}
