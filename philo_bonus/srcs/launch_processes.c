/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:40:39 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/03 13:13:28 by sdummett         ###   ########.fr       */
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
			if (philo->philo_number == 1)
				solo_philosopher_routine(philo);
			else
				process_routine(philo);
			break ;
		}
		else if (philo->pid[i] < 0)
			write(2, "fork has failed\n", ft_strlen("fork has failed\n"));
		i++;
	}
}
