/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:39:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:12:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_datas *datas)
{
	int	i;

	datas->forks = malloc(sizeof(int *) * datas->philo_number);
	i = 0;
	while (i < datas->philo_number)
	{
		datas->forks[i] = malloc(sizeof(int));
		i++;
	}
}
