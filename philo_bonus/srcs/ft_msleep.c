/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:45:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 11:57:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_msleep(unsigned long time_to_sleep)
{
	unsigned long	time_to_reach;

	time_to_reach = gettime() + time_to_sleep;
	while (gettime() < time_to_reach)
		usleep(10);
}
