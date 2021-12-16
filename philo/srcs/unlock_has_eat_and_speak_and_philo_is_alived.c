/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_has_eat_and_speak_and_philo_is_alive        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 08:45:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/16 08:49:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlock_has_eat_and_speak_and_philo_is_alived(t_philo *philo)
{
	pthread_mutex_unlock(&philo->has_eat_mutex);
	pthread_mutex_unlock(&philo->datas->speak_mutex);
	pthread_mutex_unlock(&philo->datas->all_philo_is_alived_mutex);
}
