/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:54:24 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/20 20:51:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo		*philo;
	struct timeval end, start;

	philo = arg;
	// int left_fork = philo->left_fork;
	// int right_fork = philo->right_fork;
	//printf("Hello from routine, I'm thread number %d\n", philo->id);
	gettimeofday(&start, NULL);
	while (true)
	{

		pthread_mutex_lock(philo->left_mutex);
		pthread_mutex_lock(philo->right_mutex);
		gettimeofday(&end, NULL);
		if ((end.tv_usec - start.tv_usec) > philo->datas->time_to_die)
		{
			printf("Philo %d died, he has spent %ld without eating (ttd %d) :(\n",
				philo->id, (end.tv_usec - start.tv_usec), philo->datas->time_to_die);
			return arg;
		}
		usleep(philo->datas->time_to_eat);
		pthread_mutex_unlock(philo->left_mutex);
		pthread_mutex_unlock(philo->right_mutex);
		gettimeofday(&start, NULL);
		usleep(philo->datas->time_to_sleep);		
	}
	return (arg);
}
