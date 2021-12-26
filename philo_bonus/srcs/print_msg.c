/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:12:47 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 17:02:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	print_msg(t_philo *philo, int state)
{
	unsigned long	current_time;

	sem_wait(philo->someone_speak_sem);
	current_time = gettime() - philo->simulation_start;
	sem_wait(philo->someone_died_sem);
	philo->confirm_someone_died_sem = 
		sem_open(philo->datas->confirm_someone_died_name, O_CREAT | O_EXCL, S_IRUSR | S_IWUSR, (unsigned int)1);
	if (philo->confirm_someone_died_sem != SEM_FAILED)
	{
		sem_close(philo->confirm_someone_died_sem);
		sem_unlink(philo->datas->confirm_someone_died_name);
	}
	else
	{
		sem_post(philo->someone_died_sem);
		sem_post(philo->someone_speak_sem);
		return (0);
	}
	// if (false) //someone_died)
	// {
	// 	sem_post(philo->someone_died_sem);
	// 	sem_post(philo->someone_speak_sem);
	// 	return (0);
	// }
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
