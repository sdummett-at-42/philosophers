/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_processes_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:01:33 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 17:16:24 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_processes_end(t_datas *datas)
{
	int	i;

	i = 0;
	while (i < datas->philo_number)
	{
		waitpid(*datas->pid[i], NULL, 0);
		i++;
	}
	sem_close(datas->forks_sem);
	sem_unlink(datas->forks_name);
	sem_unlink(datas->someone_died_name);
	sem_unlink(datas->someone_died_name);
}
