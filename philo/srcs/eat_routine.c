/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:08:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 15:15:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*eat_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	//usleep(100);
	pthread_mutex_lock(&philo->has_eat_mutex);
	
	philo->has_eat = EAT;
	pthread_mutex_unlock(&philo->has_eat_mutex);
	return (NULL);
}