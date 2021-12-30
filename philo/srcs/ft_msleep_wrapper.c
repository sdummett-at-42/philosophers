/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep_wrapper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:02:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/30 15:01:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_msleep_wrapper(t_philo *philo, unsigned long time_to_sleep)
{
	unsigned long	time_to_reach;

	time_to_reach = gettime() + time_to_sleep;
	while (gettime() < time_to_reach)
	{
		ft_msleep(1);
		if (check_if_someone_died(philo))
			return (0);
	}
	return (1);
}
