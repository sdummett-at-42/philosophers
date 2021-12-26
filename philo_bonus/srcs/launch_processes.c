/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:40:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 21:44:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	launch_processes(t_philo *philo)
{
	int		i;

	i = 0;
	philo->simulation_start = gettime() + 1000;
	while (i < philo->philo_number)
	{
		philo->id = i;
		philo->pid[i] = fork();
		if (philo->pid[i] == 0)
		{
			process_routine(philo);
			break ;
		}
		i++;
	}
}
