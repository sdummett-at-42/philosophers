/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:02:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 15:03:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	ft_usleep(5);
	pthread_mutex_lock(&philo->datas->someone_died_mutex);
	pthread_mutex_lock(&philo->time_must_eat_mutex);
	while (!philo->datas->someone_died && philo->time_must_eat != 0)
	{
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		pthread_mutex_unlock(&philo->time_must_eat_mutex);
		check_if_philo_died(philo);
		ft_usleep(60);
		pthread_mutex_lock(&philo->datas->someone_died_mutex);
		pthread_mutex_lock(&philo->time_must_eat_mutex);
	}
	pthread_mutex_unlock(&philo->datas->someone_died_mutex);
	pthread_mutex_unlock(&philo->time_must_eat_mutex);
	return (NULL);
}

void	check_if_philo_died(t_philo *philo)
{
	unsigned long	currtime;

	pthread_mutex_lock(&philo->last_meal_mutex);
	currtime = gettime();
	if (currtime - philo->last_meal > philo->datas->time_to_die)
	{			
		pthread_mutex_lock(&philo->datas->someone_died_mutex);
		if (!philo->datas->someone_died)
		{
			philo->datas->someone_died = true;
			print_death_msg(philo, currtime);
		}
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
}

void	print_death_msg(t_philo *philo, unsigned long currtime)
{
	pthread_mutex_lock(&philo->datas->someone_speak_mutex);
	printf(BRED "%-6ld %-2d died\n"RESET,
		currtime - philo->simulation_start, philo->id + 1);
	pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
}
