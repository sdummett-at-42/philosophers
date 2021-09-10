/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_args_to_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:12:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/10 21:01:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	//sleep(1);
	int index = *(int *)arg;
	
	printf("%d ", primes[index]);
	free(arg);
	return NULL;
}
int main()
{
	int i;
	pthread_t	th[10];

	i = 0;
	while (i < 10)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(th + i, NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			return 1;
		i++;
	}
	return 0;
}