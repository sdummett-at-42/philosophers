/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_threads_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:58:41 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 22:17:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_threads_end(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		pthread_join(*(philo->philo[i]), NULL);
		i++;
	}
}
