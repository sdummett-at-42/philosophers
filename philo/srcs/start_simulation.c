/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:55:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_simulation(t_datas *datas, char **args)
{
	
	get_simulation_data(datas, args);
	//print_struct(datas);
	init_mutexes(datas);
	init_forks(datas);
	launch_threads(datas);
	wait_threads_end(datas);
	destroy_mutexes(datas);
	frees(datas);
}
