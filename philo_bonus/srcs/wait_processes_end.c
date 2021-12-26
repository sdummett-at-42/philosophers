/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:01:33 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 21:18:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_processes_end(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_number)
	{
		waitpid(philo->pid[i], NULL, 0);
		i++;
	}
	sem_close(philo->forks_sem);
	sem_unlink(philo->forks_name);
	sem_unlink(philo->someone_died_name);
	sem_unlink(philo->someone_died_name);
}
