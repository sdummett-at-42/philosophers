/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:06:02 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/26 20:01:07 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

char	get_random_letter(void)
{
	unsigned long	c;

	c = gettime();
	while ((c % 1000) < '!' || (c % 1000) > '~')
		c = c / 2;
	if ((char)c < 0)
		c = c * -1;
	printf("[%d]", (char)c);
	return ((char)c);

}

char	*get_random_string(void)
{
	char	*new;
	int		i;

	new = ft_calloc(FILENAME_LEN, sizeof(char *));
	if (new == NULL)
	{
		printf("malloc string generator: %d", errno);
		return (NULL);
	}
	i = 0;
	while (i < FILENAME_LEN - 1)
	{
		new[i] = get_random_letter();
		ft_usleep(i % 10);
		i++;
	}
	new[i] = '\0';
	printf("\n");
	return (new);
}

char	*string_generator(void)
{
	char	*str;

	str = get_random_string();
	if (str == NULL)
		return (NULL);
	return (str);
}
