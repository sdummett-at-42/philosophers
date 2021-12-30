/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_ressources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:14:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 13:35:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	release_ressources(t_philo *philo)
{
	sem_close(philo->forks_sem);
	sem_unlink(philo->forks_name);
	sem_close(philo->someone_speak_sem);
	sem_unlink(philo->someone_speak_name);
	sem_close(philo->someone_died_sem);
	sem_unlink(philo->someone_died_name);
	free(philo->pid);
	free(philo->forks_name);
	free(philo->someone_speak_name);
	free(philo->someone_died_name);
	free(philo->confirm_someone_died_name);
}
