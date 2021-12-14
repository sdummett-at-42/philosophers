/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 21:40:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_struct(t_philo *philo)
{
	printf("numbers_of_philosophers => %d\n", philo->philo_number);
	printf("time_to_die             => %d\n", philo->time_to_die);
	printf("time_to_eat             => %d\n", philo->time_to_eat);
	printf("time_to_sleep           => %d\n", philo->time_to_sleep);
	printf("time_must_eat           => %d\n", philo->time_must_eat);
}
