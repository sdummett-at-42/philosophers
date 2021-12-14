/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_simulation_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:07:48 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 21:41:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_simulation_data(t_philo *philo, char **args)
{
	philo->philo_number = ft_atoi(args[0]);
	philo->time_to_die = ft_atoi(args[1]);
	philo->time_to_eat = ft_atoi(args[2]);
	philo->time_to_sleep = ft_atoi(args[3]);
	if (args[4] != NULL)
		philo->time_must_eat = ft_atoi(args[4]);
	else
	philo->time_must_eat = 0;
}
