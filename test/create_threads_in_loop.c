/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads_in_loop.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:07:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/12 16:19:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

pthread_mutex_t mutex;
int mails = 0;

void *routine()
{
	pthread_mutex_lock(&mutex);
	mails = mails + 20;
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t th[4];
	int i;

	pthread_mutex_init(&mutex, NULL);
	for (i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread");
		printf("Thread %d has started\n", i);
	}
	
	for (i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}