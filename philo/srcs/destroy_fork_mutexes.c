/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_fork_mutexes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:09:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 22:17:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_fork_mutexes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		pthread_mutex_destroy(philo->fork_mutex[i]);
		i++;
	}
}
