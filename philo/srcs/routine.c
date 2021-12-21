/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/21 16:35:21 by sdummett         ###   ########.fr       */
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
		// current_time = gettime() - philo->datas->simulation_start_ms;
		// printf( WHT "%-6ld %-2d is thinking\n" RESET , current_time, philo->id);
		if (print_msg(philo, THINKING) < 0)
			return NULL;

		pthread_mutex_lock(philo->left_mutex);
		// current_time = gettime() - philo->datas->simulation_start_ms;
		// printf( YEL "%-6ld %-2d has taken fork\n" RESET, current_time, philo->id);
		if (print_msg(philo, FORK_TAKEN) < 0)
			return NULL;

		pthread_mutex_lock(philo->right_mutex);
		// current_time = gettime() - philo->datas->simulation_start_ms;
		// printf( YEL "%-6ld %-2d has taken fork\n" RESET, current_time, philo->id);
		if (print_msg(philo, FORK_TAKEN) < 0)
			return NULL;
		
		end = gettime();
		if ((end - start) > (unsigned long int)philo->datas->time_to_die)
		{
			pthread_mutex_lock(&philo->datas->someone_died_mutex);
			philo->datas->someone_died = true;
			pthread_mutex_unlock(&philo->datas->someone_died_mutex);
			current_time = gettime() - philo->datas->simulation_start_ms;
			printf( BRED "%-6ld %-2d died\n" RESET, current_time, philo->id);
			return NULL;
		}

		// current_time = gettime() - philo->datas->simulation_start_ms;
		// printf( GRN "%-6ld %-2d is eating\n" RESET, current_time, philo->id);
		if (print_msg(philo, EATING) < 0)
			return NULL;

		usleep(philo->datas->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_mutex);
		pthread_mutex_unlock(philo->right_mutex);
		start = gettime();

		// current_time = gettime() - philo->datas->simulation_start_ms;
		// printf( BLU "%-6ld %-2d is sleeping\n" RESET,current_time, philo->id);
		if (print_msg(philo, SLEEPING) < 0)
			return NULL;

		usleep(philo->datas->time_to_sleep * 1000);		
	}
	return (arg);
}
