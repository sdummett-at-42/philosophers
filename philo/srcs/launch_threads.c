/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 22:22:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_philo *philo)
{
	int	i;

	philo->philo = malloc(sizeof(pthread_t *) * philo->philo_number);
	i = 0;
	while (i < philo->philo_number)
	{
		philo->philo[i] = malloc(sizeof(pthread_t));
		pthread_create(philo->philo[i], NULL, &routine, NULL);
		i++;
	}
}