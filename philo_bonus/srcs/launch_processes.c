/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:40:39 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 10:38:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	launch_processes(t_datas *datas, t_philo **philo)
{
	int		i;

	i = 0;
	while (i < datas->philo_number)
	{
		*(datas->pid[i]) = fork();
		if (*(datas->pid[i]) == 0)
		{
			process_routine(philo[i]);
			break ;
		}
		i++;
	}
}
