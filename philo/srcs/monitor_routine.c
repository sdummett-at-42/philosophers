/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:02:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 17:00:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo			*philo;
	unsigned long	currtime;

	philo = arg;
	ft_usleep(5);
	while (true)
	{
		pthread_mutex_lock(&philo->last_meal_mutex);
		currtime = gettime();
		if (currtime - philo->last_meal >= philo->datas->time_to_die)
		{
			pthread_mutex_unlock(&philo->last_meal_mutex);
			pthread_mutex_lock(&philo->time_must_eat_mutex);
			if (philo->time_must_eat == 0)
			{
				pthread_mutex_unlock(&philo->time_must_eat_mutex);
				break ;
			}
			pthread_mutex_unlock(&philo->time_must_eat_mutex);
			pthread_mutex_lock(&philo->datas->someone_died_mutex);
			if (!philo->datas->someone_died)
			{
				philo->datas->someone_died = true;
				pthread_mutex_unlock(&philo->datas->someone_died_mutex);
				print_death_msg(philo, currtime);
				break ;
			}
			pthread_mutex_unlock(&philo->datas->someone_died_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->last_meal_mutex);
		pthread_mutex_lock(&philo->time_must_eat_mutex);
		if (philo->time_must_eat == 0)
		{
			pthread_mutex_unlock(&philo->time_must_eat_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->time_must_eat_mutex);
		ft_usleep(5);
	}
	return (NULL);
}

void	print_death_msg(t_philo *philo, unsigned long currtime)
{
	pthread_mutex_lock(&philo->datas->someone_speak_mutex);
	printf(BRED "%-6ld %-2d died\n"RESET,
		currtime - philo->simulation_start, philo->id + 1);
	pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
}
