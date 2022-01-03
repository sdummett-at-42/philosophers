/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:00 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/03 13:03:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	start_simulation(t_philo *philo, char **args)
{
	if (!(init_simulation(philo, args)))
	{
		printf(BRED"Simulation initialization error\n"RESET);
		return (0);
	}
	launch_processes(philo);
	wait_processes_end(philo);
	return (1);
}
