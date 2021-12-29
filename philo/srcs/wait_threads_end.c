/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:58:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:18:42 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_threads_end(t_datas *datas)
{
	int		i;

	i = 0;
	while (i < datas->philo_number)
	{
		pthread_join(*(datas->philo_thread[i]), NULL);
		// pthread_mutex_destroy(&philo->last_meal_mutex);
		// free(philo);
		i++;
	}
}
