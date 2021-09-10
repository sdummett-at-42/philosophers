/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_array_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:12:55 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/10 21:01:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	//sleep(1);
	int index = *(int *)arg;
	
	int sum = 0;
	for (int j = 0; j < 5; j++)
	{
		sum += primes[index + j];
	}
	printf("Local sum: %d\n", sum);
	*(int *)arg = sum;
	return arg;
}
int main()
{
	int i;
	pthread_t	th[2];

	i = 0;
	while (i < 2)
	{
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if (pthread_create(th + i, NULL, &routine, a) != 0)
		{
			perror("Failed to create thread");
			return 1;
		}
		i++;
	}
	int globalSum = 0;
	i = 0;
	while (i < 2)
	{
		int *r;

		if (pthread_join(th[i], (void **)&r) != 0)
		{
			perror("Failed to join thread");
			return 1;
		}
		globalSum += *r;
		free(r);
		i++;
	}
	printf("Global sum: %d\n", globalSum);
	return 0;
}