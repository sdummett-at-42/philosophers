/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/20 19:23:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	printf("Hello from routine, I'm thread number %d\n", philo->id);
	gettimeofday(&philo->start, NULL);
	while (true)
	{

		pthread_mutex_lock(philo->datas->fork_mutex[philo->left_fork]);
		pthread_mutex_lock(philo->datas->fork_mutex[philo->right_fork]);
		gettimeofday(&philo->end, NULL);
		if ((philo->end.tv_usec - philo->start.tv_usec) > philo->datas->time_to_die)
		{
			printf("Philo %d died, he has spent %ld without eating (ttd %d) :(\n",
				philo->id, (philo->end.tv_usec - philo->start.tv_usec), philo->datas->time_to_die);
			return arg;
		}
		else
			usleep(philo->datas->time_to_eat);
		pthread_mutex_unlock(philo->datas->fork_mutex[philo->left_fork]);
		pthread_mutex_unlock(philo->datas->fork_mutex[philo->right_fork]);
		gettimeofday(&philo->start, NULL);
		usleep(philo->datas->time_to_sleep);		
	}
	return (arg);
}
