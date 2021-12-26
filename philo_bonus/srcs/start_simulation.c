/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 20:00:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_simulation(t_datas *datas, char **args)
{
	t_philo	**philo;
	(void)philo;

	get_simulation_data(datas, args);
	philo = init_philos(datas);
	// for (int i = 0; i < 10; i++){
	// 	printf("%s\n", string_generator());
	// }

	// launch_processes(datas, philo);
	// wait_processes_end(datas);


	// sem_unlink("forks");
	// free(datas->d_name);
	// init_mutexes(datas);
	// launch_threads(datas, philo);
	// wait_threads_end(datas);
	// destroy_mutexes(datas);
	// frees(datas);
	// free(philo);
}
