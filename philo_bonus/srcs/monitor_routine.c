/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 22:33:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 15:22:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitor_routine(void *arg)
{
	t_philo				*philo;

	philo = arg;
	ft_msleep(5);
	sem_wait(philo->someone_died_sem);
	pthread_mutex_lock(&philo->time_must_eat_mutex);
	while (philo->time_must_eat != 0)
	{
		sem_post(philo->someone_died_sem);
		pthread_mutex_unlock(&philo->time_must_eat_mutex);
		if (check_if_philo_died(philo))
			return (NULL);
		ft_msleep(1);
		pthread_mutex_lock(&philo->time_must_eat_mutex);
		sem_wait(philo->someone_died_sem);
	}
	sem_post(philo->someone_died_sem);
	pthread_mutex_unlock(&philo->time_must_eat_mutex);
	return (NULL);
}

int	check_if_philo_died(t_philo *philo)
{
	unsigned long	currtime;

	currtime = gettime();
	pthread_mutex_lock(&philo->last_meal_mutex);
	if (currtime - philo->last_meal > philo->time_to_die)
	{
		sem_wait(philo->someone_died_sem);
		philo->confirm_someone_died_sem = sem_open(
				philo->confirm_someone_died_name,
				O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, (unsigned int)1);
		if (philo->confirm_someone_died_sem != SEM_FAILED)
		{
			print_death_msg(philo, currtime);
			sem_close(philo->confirm_someone_died_sem);
		}
		pthread_mutex_unlock(&philo->last_meal_mutex);
		sem_post(philo->someone_died_sem);
		return (1);
	}
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (0);
}

void	print_death_msg(t_philo *philo, unsigned long currtime)
{
	sem_wait(philo->someone_speak_sem);
	printf(BRED "%-6ld %-2d died\n"RESET,
		currtime - philo->simulation_start, philo->id + 1);
	sem_post(philo->someone_speak_sem);
}
