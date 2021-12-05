/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_trylock_example.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:53:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/12 14:23:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

// chefs = threads
// stove = shared date (+mutex)

pthread_mutex_t stoveMutexes[4];
int stoveFuel[4] = {100, 100, 100, 100};

void	*routine(void *args)
{
	for (int i = 0; i < 4; i++)
	{
		if (pthread_mutex_trylock(&stoveMutexes[i]) == 0)
		{
			int fuelNeeded = (rand() % 30);
			if (stoveFuel - fuelNeeded < 0)
				printf("No more fuel... Going home\n");
			else
			{
				stoveFuel[i] -= fuelNeeded;
				usleep(500000);
				printf("Fuel left %d\n", stoveFuel[i]);
			}
			pthread_mutex_unlock(&stoveMutexes[i]);
			break ;
		}
		else
		{
			if (i == 3)
			{
				printf("No stove available yet, waiting...\n");
				usleep(300000);
				i = 0;
			}
		}
		
	}
	return NULL;
}

int main()
{
	pthread_t th[10];

	srand(time(NULL));
	for (int i = 0; i < 4; i++)
		pthread_mutex_init(&stoveMutexes[i], NULL);
	for (int i = 0; i < 10; i++){
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0; i < 10; i++){
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	for (int i = 0; i < 4; i++)
		pthread_mutex_destroy(&stoveMutexes[i]);
}