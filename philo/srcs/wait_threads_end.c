/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:58:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 16:36:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_threads_end(t_datas *datas)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < datas->philo_number)
	{
		pthread_join(*(datas->philo[i]), (void *)&philo);
		pthread_mutex_destroy(&philo->is_eating_mutex);
		free(philo);
		i++;
	}
}
