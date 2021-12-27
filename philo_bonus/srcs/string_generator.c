/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:06:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/27 13:11:44 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

char	*string_generator(void)
{
	char	*new;
	int		i;

	new = ft_calloc(FILENAME_LEN, sizeof(char *));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < FILENAME_LEN - 1)
	{
		new[i] = '/';
		while (new[i] == '/')
			new[i] = ft_rand(33, 127);
		ft_msleep(i % 10);
		i++;
	}
	new[i] = '\0';
	return (new);
}
