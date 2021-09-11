/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trylock_and_lock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 15:25:59 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/11 15:38:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

pthread_mutex_t	mutex;

void 	*routine(void *arg)
{
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("Got lock\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else{
		printf("Didn't get lock\n");
	}
	return NULL;
}

int main()
{
	int			i;
	pthread_t	th[4];

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 4)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
		{
			perror("Error at creating thread");
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			perror("Error joining thread");
			return 2;
		}
		i++;
	}
	return 0;
}