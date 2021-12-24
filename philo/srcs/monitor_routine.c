/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:02:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 12:03:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo				*philo;
	unsigned long		currtime;

	philo = arg;
	ft_usleep(10);
	while (!philo->datas->someone_died && philo->time_must_eat != 0)
	{
		pthread_mutex_lock(&philo->last_meal_mutex);
		currtime = gettime();
		if (currtime - philo->last_meal >= philo->datas->time_to_die)
		{			
			pthread_mutex_lock(&philo->datas->someone_died_mutex);
			if (!philo->datas->someone_died)
			{
				philo->datas->someone_died = true;
				pthread_mutex_lock(&philo->datas->someone_speak_mutex);
				printf(BRED "%-6ld %-2d died\n"RESET,
					currtime - philo->simulation_start, philo->id);
				pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
			}
			pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		}
		pthread_mutex_unlock(&philo->last_meal_mutex);
		ft_usleep(10);
	}
	return (NULL);
}
