/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_speak_and_philo_is_alived.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:53:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/16 08:54:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_speak_and_philo_is_alived(t_philo *philo)
{
	pthread_mutex_lock(&philo->datas->speak_mutex);
	pthread_mutex_lock(&philo->datas->all_philo_is_alived_mutex);
}
