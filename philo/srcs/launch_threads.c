/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:56:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:17:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_datas *datas)//, t_philo **philo)
{
	int		i;

	i = 0;
	datas->simulation_start = gettime() + 1000;
	while (i < datas->philo_number)
	{
		pthread_create(datas->philo_thread[i], NULL, &routine, datas->philo[i]);
		i++;
	}
}
