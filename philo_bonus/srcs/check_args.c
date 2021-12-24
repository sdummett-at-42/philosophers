/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:48:36 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/24 20:21:35 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (!is_number(args[i]))
			return (0);
		i++;
	}
	return (1);
}
