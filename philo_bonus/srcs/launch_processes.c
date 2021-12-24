/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:40:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 21:01:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	launch_processes(t_datas *datas, t_philo **philo)
{
	int		i;
	sem_t	*forks;

	forks = sem_open("forks", datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		if (fork() == 0)
		{
			start_diner(philo[i]);
			break ;
		}
		i++;
	}
}
