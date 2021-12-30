/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:45:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/30 15:02:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_msleep(unsigned long time_to_sleep)
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
