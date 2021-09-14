/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_example.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 17:40:38 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/14 18:32:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

# define THREAD_NUM 16

sem_t semaphore;

void *routine(void *args)
{
	printf("(%d) Waiting in the login queue\n", *(int *)args);
	sem_wait(&semaphore);
	printf("(%d) Logged in\n", *(int *)args);
	sleep(rand() % 5 + 1);
	printf("(%d) Logged out\n", *(int *)args);
	sem_post(&semaphore);
	free(args);
	return NULL;
}

int main()
{
	pthread_t th[THREAD_NUM];

	sem_init(&semaphore, 0, 4);
	int i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			perror("Failed to create thread");
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	sem_destroy(&semaphore);
	return 0;
}