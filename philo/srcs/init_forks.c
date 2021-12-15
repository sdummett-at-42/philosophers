/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:39:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 10:42:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_philo *philo)
{
	int	i;

	philo->forks = malloc(sizeof(int *) * philo->philo_number);
	i = 0;
	while (i < philo->philo_number)
	{
		philo->forks[i] = malloc(sizeof(int));
		i++;
	}
}
