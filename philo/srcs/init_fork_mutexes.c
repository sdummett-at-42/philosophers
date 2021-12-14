/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork_mutexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:01:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 22:23:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_fork_mutexes(t_philo *philo)
{
	int	i;

	philo->fork_mutex = malloc(sizeof(pthread_mutex_t *) * philo->philo_number);
	
	i = 0;
	while (i < philo->philo_number)
	{
		philo->fork_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo->fork_mutex[i], NULL);
		i++;
	}
}
