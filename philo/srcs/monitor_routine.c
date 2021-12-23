/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:02:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/23 13:40:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo				*philo;
	unsigned long		currtime;

	philo = arg;
	while (gettime() < philo->datas->simulation_start_ms + 1);

	while (!philo->datas->someone_died)
	{
		pthread_mutex_lock(&philo->last_meal_mutex);
		currtime = gettime();
		if (currtime - philo->last_meal >= (unsigned long)philo->datas->time_to_die)
		{
			pthread_mutex_lock(&philo->datas->someone_died_mutex);

			philo->datas->someone_died = true;
			pthread_mutex_unlock(&philo->datas->someone_died_mutex);
			printf( BRED "%-6ld %-2d died | diff => %ld | last_meal => %ld\n" RESET,
				 currtime - philo->datas->simulation_start_ms, philo->id, currtime - philo->last_meal, philo->last_meal - philo->datas->simulation_start_ms); // Take the first gettime();
		}
		pthread_mutex_unlock(&philo->last_meal_mutex);
		// printf("Hello World!\n");
		// usleep(60 * 1000);
	}
	return NULL;
}