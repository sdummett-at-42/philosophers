/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:38:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:09:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_struct(t_datas *datas)
{
	printf("numbers_of_philosophers => %d\n", datas->philo_number);
	printf("time_to_die             => %d\n", datas->time_to_die);
	printf("time_to_eat             => %d\n", datas->time_to_eat);
	printf("time_to_sleep           => %d\n", datas->time_to_sleep);
	printf("time_must_eat           => %d\n", datas->time_must_eat);
}
