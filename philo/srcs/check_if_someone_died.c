/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_someone_died.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:55:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 18:59:18 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	check_if_someone_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->datas->someone_died_mutex);
	if (philo->datas->someone_died)
	{
		pthread_mutex_unlock(&philo->datas->someone_died_mutex);
		return (true);
	}
	pthread_mutex_unlock(&philo->datas->someone_died_mutex);
	return (false);
}
