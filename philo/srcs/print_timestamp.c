/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_timestamp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:16:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_timestamp(t_philo *philo, int state)
{
	unsigned long	current_time;

	pthread_mutex_lock(&philo->datas->someone_died_mutex);
	pthread_mutex_lock(&philo->datas->someone_speak_mutex);
	current_time = gettime() - philo->datas->simulation_start;
	if (philo->datas->someone_died)
	{
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
		return (0);
	}
	if (state == THINKING)
		printf(MAG "%-6ld %-3d is thinking\n"RESET,
			current_time, philo->id + 1);
	if (state == FORK_TAKEN)
		printf(YEL "%-6ld %-3d has taken fork\n"RESET,
			current_time, philo->id + 1);
	if (state == EATING)
		printf(GRN "%-6ld %-3d is eating\n"RESET,
			current_time, philo->id + 1);
	if (state == SLEEPING)
		printf(BLU "%-6ld %-3d is sleeping\n"RESET, current_time, philo->id + 1);
	pthread_mutex_unlock(&philo->datas->someone_died_mutex);
	pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
	return (1);
}
