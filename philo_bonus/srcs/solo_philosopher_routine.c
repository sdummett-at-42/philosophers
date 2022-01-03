/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_philosopher_routine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:15 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/03 15:26:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	solo_philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (gettime() < philo->simulation_start)
		ft_msleep(1);
	print_timestamp(philo, FORK_TAKEN);
	ft_msleep(philo->time_to_die);
	print_death_msg(philo, gettime());
	release_subprocess_ressources(philo);
	exit(0);
}
