/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:47:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/16 10:17:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	**init_philos(t_datas *datas)
{
	int		i;
	t_philo	**philo;

	philo = malloc(sizeof(t_philo *) * datas->philo_number);
	datas->philo = malloc(sizeof(pthread_t *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->philo[i] = malloc(sizeof(pthread_t));
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->id = i;
		philo[i]->has_eat = NOT_EAT;
		philo[i]->datas = datas;
		if (philo[i]->id == 0)
			philo[i]->right_fork = philo[i]->datas->philo_number - 1;
		else
			philo[i]->right_fork = philo[i]->id - 1;
		if (philo[i]->id == philo[i]->datas->philo_number - 1)
			philo[i]->left_fork = philo[i]->datas->philo_number - philo[i]->datas->philo_number;
		else
			philo[i]->left_fork = philo[i]->id ;
		printf("ID => %d | RIGHT FORK => %d | LEFT FORK %d\n", philo[i]->id, philo[i]->right_fork, philo[i]->left_fork);
		pthread_mutex_init(&philo[i]->has_eat_mutex, NULL);
		i++;
	}
	return (philo);
}
