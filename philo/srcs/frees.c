/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:40:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 10:41:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_threads(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		free(datas->philo[i]);
		i++;
	}
	free(datas->philo);
}

void	free_mutexes(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		free(datas->fork_mutex[i]);
		i++;
	}
	free(datas->fork_mutex);
}

void	frees(t_datas *datas)
{
	free_threads(datas);
	free_mutexes(datas);
}
