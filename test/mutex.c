/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:56:07 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/10 21:01:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	int i = 0;

	while (i < 10000000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
	return NULL;
}

int main()
{
	pthread_t	t1, t2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(t1, NULL) != 0)
		return 2;
	if (pthread_join(t2, NULL) != 0)
		return 3;
	printf("mails received: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return 0;
}