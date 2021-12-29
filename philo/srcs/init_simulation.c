/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simulation_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 15:50:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_simulation(t_datas *datas, char **args)
{
	int	i;

	datas->philo_number = ft_atoi(args[0]);
	datas->time_to_die = ft_atoi(args[1]);
	datas->time_to_eat = ft_atoi(args[2]);
	datas->time_to_sleep = ft_atoi(args[3]);
	if (args[4] != NULL)
		datas->time_must_eat = ft_atoi(args[4]);
	else
		datas->time_must_eat = -1;
	datas->someone_died = false;
	datas->forks = ft_calloc(datas->philo_number, sizeof(int *));
	i = 0;
	while (i < datas->philo_number)
	{
		datas->forks[i] = ft_calloc(1, sizeof(int));
		i++;
	}
	init_mutexes(datas);
	init_philos(datas);
}