/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_philosopher_routine.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 17:57:15 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/02 18:12:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*solo_philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (gettime() < philo->datas->simulation_start)
		ft_msleep(1);
	print_timestamp(philo, FORK_TAKEN);
	ft_msleep(philo->datas->time_to_die);
	print_death_msg(philo, gettime());
	return (NULL);
}
