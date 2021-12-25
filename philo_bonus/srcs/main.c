/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:38:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/25 19:25:12 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

bool someone_died = false;

int	main(int ac, char **av)
{
	t_datas	datas;
	(void)datas;

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
	printf(BMAG"Hello world!\n"RESET);
	//sem_open("forks", O_CREAT | O_EXCL | S_IRWXU, ft_atoi(av[1]));
	return (0);
}