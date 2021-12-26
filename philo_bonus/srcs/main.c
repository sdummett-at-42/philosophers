/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:38:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 17:14:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int ac, char **av)
{
	t_datas	datas;

	if (ac < 5 || ac > 6)
	{
		ft_strerror(BRED"Error: Not enough or too much arguments\n"RESET);
		return (1);
	}
	if (!check_args(av + 1))
	{
		ft_strerror(BRED"Error: Bad arguments\n"RESET);
		return (2);
	}
	start_simulation(&datas, av + 1);
	printf(BMAG"End of the simulation,\n"RESET);
	return (0);
}
