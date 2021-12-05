/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_variables_signal_vs_broadcast.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:40:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/12 13:52:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int fuel = 0;
pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

void *fuel_filling(void *arg)
{
	int i = 0;
	while (i < 5)
	{
		pthread_mutex_lock(&mutexFuel);
		fuel = fuel + 30;
		printf("Filled fuel... %d\n\n", fuel);
		pthread_mutex_unlock(&mutexFuel);
		pthread_cond_broadcast(&condFuel);
		sleep(1);
	}
	return NULL;
}

void	*car(void *arg)
{
	pthread_mutex_lock(&mutexFuel);
	while (fuel < 40)
	{
		printf("No fuel. Waiting...\n");
		pthread_cond_wait(&condFuel, &mutexFuel);
		sleep(1);
	}
	fuel = fuel - 40;
	printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutexFuel);
	// sleep(1);	
	return NULL;
}

int main()
{
	int i;
	pthread_t	th[6];

	pthread_mutex_init(&mutexFuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	i = 0;
	while (i < 6)
	{
		if (i == 4 || i == 5)
		{
			if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
				perror("Failed to create thread");
		}
		else
		{
			if (pthread_create(&th[i], NULL, &car, NULL) != 0)
				perror("Failed to create thread");
		}
		i++;
	}

	i = 0;
	while (i < 6)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
		i++;
	}
	pthread_mutex_destroy(&mutexFuel);
	pthread_cond_destroy(&condFuel);
	return 0;
}