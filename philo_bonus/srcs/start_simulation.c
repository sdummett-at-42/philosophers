/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 21:09:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_simulation(t_philo *philo, char **args)
{
	get_simulation_data(philo, args);
//	philo = init_philos(philo);
	launch_processes(philo);
	wait_processes_end(philo);


	// sem_unlink("forks");
	// free(datas->d_name);
	// init_mutexes(datas);
	// launch_threads(datas, philo);
	// wait_threads_end(datas);
	// destroy_mutexes(datas);
	// frees(datas);
	// free(philo);
}
