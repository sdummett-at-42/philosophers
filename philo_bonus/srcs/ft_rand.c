/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:35:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:45:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

/* Any nonzero start state will work. */
/* check for valid range.             */
/* get the random in end-range.       */
/* get the random in start-range.     */

unsigned int	ft_rand(unsigned int start_range, unsigned int end_range)
{
	static unsigned int	rand = 0xACE42;

	if (start_range == end_range)
		return (start_range);
	rand = rand + (unsigned int)gettime() % 100000;
	rand = rand % end_range;
	while (rand < start_range)
		rand = rand + end_range - start_range;
	return (rand);
}
