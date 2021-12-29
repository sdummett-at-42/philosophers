/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/29 20:29:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_usage(void)
{
	ft_strerror(BBLU"Usage: philo number_of_philosophers time_to_die "
		"time_to_eat time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n"RESET);
}

int	main(int ac, char **av)
{
	t_datas	datas;

	if (ac < 5 || ac > 6)
	{
		ft_strerror(BRED"Error: Not enough or too much arguments\n"RESET);
		print_usage();
		return (1);
	}
	if (!check_args(av + 1))
	{
		ft_strerror(BRED"Error: Bad arguments\n"RESET);
		print_usage();
		return (2);
	}
	memset(&datas, 0, sizeof(t_datas));
	if (!init_simulation(&datas, av + 1))
		printf(BRED"Something wrong happened\n"RESET);
	else
	{
		start_simulation(&datas);
		printf(BMAG"End of the simulation\n"RESET);
	}
	release_ressources(&datas);
	return (0);
}
