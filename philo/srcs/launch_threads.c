/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 14:34:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_datas *datas)
{
	int		i;
	t_philo	*philo;

	datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo[i] = malloc(sizeof(pthread_t));
		philo = malloc(sizeof(t_philo));
		philo->id = i;
		philo->has_eat = NOT_EAT;
		philo->datas = datas;
		pthread_mutex_init(&philo->has_eat_mutex, NULL);
		pthread_create(datas->philo[i], NULL, &routine, philo);
		i++;
	}
}
