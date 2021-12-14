/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:48:36 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 20:49:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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