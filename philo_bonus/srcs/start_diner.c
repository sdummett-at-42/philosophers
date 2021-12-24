/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:45:06 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 21:00:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	start_diner(t_philo *philo)
{
	while (true)
	{
		printf(BYEL"Hello from start diner.\n"RESET);
		printf("I'm philo %d\n", philo->id);
		break ;
		// Do simulation
	}
	exit(0);
}