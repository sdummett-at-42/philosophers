/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:09:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 16:17:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		pthread_mutex_destroy(datas->fork_mutex[i]);
		i++;
	}
	pthread_mutex_init(&datas->all_philo_is_alived_mutex, NULL);
	pthread_mutex_init(&datas->speak_mutex, NULL);
}
