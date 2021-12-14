/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:59:00 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/14 20:53:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
	{
		ft_strerror("Error: Not enough or too much arguments\n");
		return (1);
	}
	if (!check_args(av + 1))
	{
		printf("ret => %d\n", ret);
		ft_strerror("Error: Bad arguments\n");
		return (2);
	}
	return (0);
}