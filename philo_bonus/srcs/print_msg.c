/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 20:44:39 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	print_msg(t_philo *philo, int state)
{
	unsigned long	current_time;

	if (sem_wait(philo->someone_died_sem) == EINVAL)
	{
		printf("EINVAL\n");
		return (0);
	}
	sem_wait(philo->someone_speak_sem);
	current_time = gettime() - philo->simulation_start;
	if (someone_died)
	{
		sem_post(philo->someone_died_sem);
		sem_post(philo->someone_speak_sem);
		return (0);
	}
	if (state == THINKING)
		printf(MAG "%-6ld %-2d is thinking\n"RESET,
			current_time, philo->id + 1);
	if (state == FORK_TAKEN)
		printf(YEL "%-6ld %-2d has taken fork\n"RESET,
			current_time, philo->id + 1);
	if (state == EATING)
		printf(GRN "%-6ld %-2d is eating\n"RESET,
			current_time, philo->id + 1);
	if (state == SLEEPING)
		printf(BLU "%-6ld %-2d is sleeping\n"RESET, current_time, philo->id + 1);
	sem_post(philo->someone_died_sem);
	sem_post(philo->someone_speak_sem);
	return (1);
}
