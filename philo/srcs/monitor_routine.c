/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:02:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:31:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo			*philo;

	philo = arg;
	if (philo->id % 2)
		ft_msleep(30 + 2);
	else
		ft_msleep(2);
	while (true)
	{
		if (philo_died(philo))
			break ;
		if (philo_ate_enough(philo))
			break ;
		ft_msleep(2);
	}
	return (NULL);
}

bool	philo_died(t_philo *philo)
{
	unsigned long	currtime;

	pthread_mutex_lock(&philo->last_meal_mutex);
	currtime = gettime();
	if (currtime - philo->last_meal >= philo->datas->time_to_die)
	{
		pthread_mutex_unlock(&philo->last_meal_mutex);
		pthread_mutex_lock(&philo->datas->someone_died_mutex);
		if (!philo->datas->someone_died)
		{
			philo->datas->someone_died = true;
			pthread_mutex_unlock(&philo->datas->someone_died_mutex);
			print_death_msg(philo, currtime);
			return (true);
		}
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (false);
}

int	philo_ate_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->time_must_eat_mutex);
	if (philo->time_must_eat == 0)
	{
		pthread_mutex_unlock(&philo->time_must_eat_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->time_must_eat_mutex);
	return (false);
}

void	print_death_msg(t_philo *philo, unsigned long currtime)
{
	pthread_mutex_lock(&philo->datas->someone_speak_mutex);
	printf(BRED "%-6ld %-2d died\n"RESET,
		currtime - philo->datas->simulation_start, philo->id + 1);
	pthread_mutex_unlock(&philo->datas->someone_speak_mutex);
}
