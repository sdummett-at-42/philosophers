/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_return_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:34:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/10 21:01:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int mails = 0;
pthread_mutex_t mutex;

void	*roll_dice()
{
	int value = (rand() % 6) + 1;
	int *result = malloc(sizeof(int));
	//printf("%d\n", value);
	*result = value;
	printf("Thread result %p\n", result);
	return (void *)result;
}

int main()
{
	int i;
	int *res;
	pthread_t th[4];

	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 4)
	{
		if (pthread_create(th + i, NULL, &roll_dice, NULL) != 0)
		{
			perror("Failed to create thread");
			return 1;
		}
		printf("Thread %d created\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(th[i], (void **)&res) != 0)
			return 2;
		printf("Thread %d has finished execution\n", i);
		printf("Main result %p\n", res);
		printf("result: %d\n", *res);
		free(res);
		i++;
	}

	pthread_mutex_destroy(&mutex);
}