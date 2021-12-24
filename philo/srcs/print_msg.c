/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 11:17:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print_msg(t_philo *philo, int state)
{
	unsigned long	current_time;

	current_time = gettime() - philo->simulation_start;
	if (philo->datas->someone_died)
	{
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		return (0);
	}
	pthread_mutex_lock(&philo->datas->someone_speak_mutex);
	if (state == THINKING)
		printf(MAG "%-6ld %-2d is thinking\n"RESET, current_time, philo->id);
	if (state == FORK_TAKEN)
		printf(YEL "%-6ld %-2d has taken fork\n"RESET, current_time, philo->id);
	if (state == EATING)
		printf(GRN "%-6ld %-2d is eating\n"RESET, current_time, philo->id);
	if (state == SLEEPING)
		printf(BLU "%-6ld %-2d is sleeping\n"RESET, current_time, philo->id);
	pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
	return (1);
}
