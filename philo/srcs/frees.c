/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:40:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:27:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	frees(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		free(datas->fork_mutex[i]);
		free(datas->forks[i]);
		free(datas->philo_thread[i]);
		i++;
	}
	free(datas->fork_mutex);
	free(datas->forks);
	free(datas->philo_thread);
	free(datas->philo);
}
