/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/23 21:44:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_struct(t_datas *datas)
{
	printf("numbers_of_philosophers => %d\n", datas->philo_number);
	printf("time_to_die             => %ld\n", datas->time_to_die);
	printf("time_to_eat             => %ld\n", datas->time_to_eat);
	printf("time_to_sleep           => %ld\n", datas->time_to_sleep);
	printf("time_must_eat           => %ld\n", datas->time_must_eat);
}
