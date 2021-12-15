/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/15 13:13:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_datas	datas;

	if (ac < 5 || ac > 6)
	{
		ft_strerror("Error: Not enough or too much arguments\n");
		return (1);
	}
	if (!check_args(av + 1))
	{
		ft_strerror("Error: Bad arguments\n");
		return (2);
	}
	start_simulation(&datas, av + 1);
	return (0);
}
