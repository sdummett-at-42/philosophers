/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 09:46:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_philo *philo, char **args)
{
	get_simulation_data(philo, args);
	print_struct(philo);
	init_fork_mutexes(philo);
	launch_threads(philo);
	wait_threads_end(philo);
	destroy_fork_mutexes(philo);
	frees(philo);
}
