/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:53:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 23:42:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

t_philo	**init_philos(t_datas *datas)
{
	int		i;
	t_philo	**philo;

	philo = malloc(sizeof(t_philo *) * datas->philo_number);
	// datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	datas->pid = malloc(sizeof(pid_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->pid[i] = malloc(sizeof(pid_t));
		// datas->philo[i] = malloc(sizeof(pthread_t));
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->datas = datas;
		philo[i]->time_must_eat = datas->time_must_eat;
		// pthread_mutex_init(&philo[i]->last_meal_mutex, NULL);
		// pthread_mutex_init(&philo[i]->time_must_eat_mutex, NULL);
		i++;
	}
	return (philo);
}
