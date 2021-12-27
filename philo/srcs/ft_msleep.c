/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:45:09 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 19:09:52 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_msleep(unsigned long time_to_sleep)
{
	unsigned long	time_to_reach;

	time_to_reach = gettime() + time_to_sleep;
	while (gettime() < time_to_reach)
		usleep(10);
}
