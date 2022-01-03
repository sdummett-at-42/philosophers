/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:01:33 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/03 15:20:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_processes_end(t_philo *philo)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = waitpid(-1, NULL, 0);
	while (i < philo->philo_number)
	{
		if (*(philo->pid) != pid)
			kill(*(philo->pid), SIGTERM);
		i++;
	}
	sem_close(philo->forks_sem);
	sem_unlink(philo->forks_name);
	sem_unlink(philo->someone_died_name);
	sem_unlink(philo->someone_died_name);
}
