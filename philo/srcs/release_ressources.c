/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:32:22 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:55:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	release_ressources(t_datas *datas)
{
	int	i;

	i = 0;
	destroy_mutexes(datas);
	while (i < datas->philo_number)
	{
		free(datas->fork_mutex[i]);
		free(datas->forks[i]);
		free(datas->philo_thread[i]);
		free(datas->philo[i]);
		i++;
	}
	free(datas->fork_mutex);
	free(datas->forks);
	free(datas->philo_thread);
	free(datas->philo);
}