/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:23:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_datas *datas)
{
	int	i;
	t_philo	*philo;

	datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo[i] = malloc(sizeof(pthread_t));
		philo = malloc(sizeof(t_philo));
		philo->id = i;
		philo->datas = datas;
		pthread_create(datas->philo[i], NULL, &routine, philo);
		i++;
	}
}
