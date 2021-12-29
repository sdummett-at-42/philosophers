/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:01:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:47:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutexes(t_datas *datas)
{
	int	i;

	datas->fork_mutex = ft_calloc(datas->philo_number, sizeof(pthread_mutex_t *));
	i = 0;
	while (i < datas->philo_number)
	{
		datas->fork_mutex[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(datas->fork_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&datas->someone_died_mutex, NULL);
	pthread_mutex_init(&datas->someone_speak_mutex, NULL);
}
