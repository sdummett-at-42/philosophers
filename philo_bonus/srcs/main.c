/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 18:38:55 by sdummett          #+#    #+#             */
/*   Updated: 2022/01/03 14:58:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
	{
		ft_strerror(BRED"Error: Not enough or too much arguments\n"RESET);
		ft_strerror(BBLU"Usage: philo_bonus number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]\n"RESET);
		return (1);
	}
	if (!check_args(av + 1))
	{
		ft_strerror(BRED"Error: Bad arguments\n"RESET);
		ft_strerror(BBLU"Usage: philo_bonus number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]\n"RESET);
		return (2);
	}
	memset(&philo, 0, sizeof(t_philo));
	if (!(start_simulation(&philo, av + 1)))
		printf("Something wrong happened\n");
	return (0);
}
