/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:01:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/23 21:42:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutexes(t_datas *datas)
{
	int	i;

	datas->fork_mutex = malloc(sizeof(pthread_mutex_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->fork_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(datas->fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&datas->someone_died_mutex, NULL);
}
