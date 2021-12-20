/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/21 00:15:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*routine(void *arg)
{
	t_philo		*philo;
	unsigned long int	start;
	unsigned long int	end;
	unsigned long int	current_time;

	philo = arg;
	start = gettime();
	while (true)
	{
		current_time = gettime() - philo->datas->simulation_start_ms;
		printf("%-6ld %-2d is thinking\n", current_time, philo->id);
		pthread_mutex_lock(philo->left_mutex);
		current_time = gettime() - philo->datas->simulation_start_ms;
		printf("%-6ld %-2d has taken fork\n", current_time, philo->id);
		pthread_mutex_lock(philo->right_mutex);
		current_time = gettime() - philo->datas->simulation_start_ms;
		printf("%-6ld %-2d has taken fork\n", current_time, philo->id);
		end = gettime();
		if ((end - start) > (unsigned long int)philo->datas->time_to_die)
		{
			printf("Philo %d died, he has spent %ld without eating (ttd %d) :(\n",
				philo->id, (end - start), philo->datas->time_to_die);
			return arg;
		}
		current_time = gettime() - philo->datas->simulation_start_ms;
		printf("%-6ld %-2d is eating\n", current_time, philo->id);
		usleep(philo->datas->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_mutex);
		pthread_mutex_unlock(philo->right_mutex);
		start = gettime();
		current_time = gettime() - philo->datas->simulation_start_ms;
		printf("%-6ld %-2d is sleeping\n",current_time, philo->id);
		usleep(philo->datas->time_to_sleep * 1000);		
	}
	return (arg);
}
