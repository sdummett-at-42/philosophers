/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_barrier_example.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:14:42 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/14 15:47:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

#define THREAD_NUM 8

pthread_barrier_t barrierRolledDice;
pthread_barrier_t barrierCalculated;

int diceValues[8];
int status[8] ={0};

void	*rollDice(void *args)
{
	int index = *(int *)args;
	diceValues[index] = rand() % 6 + 1;
	pthread_barrier_wait(&barrierRolledDice);
	pthread_barrier_wait(&barrierCalculated);
	if (status[index] == 1)
		printf("(%d rolled [%d]) I won\n", index, diceValues[index]);
	else
		printf("(%d rolled [%d]) I lost\n", index, diceValues[index]);
	free(args);
	return NULL;
}


int main()
{
	int			i;
	int			max;
	pthread_t	th[THREAD_NUM];

	pthread_barrier_init(&barrierRolledDice, NULL, THREAD_NUM + 1);
	pthread_barrier_init(&barrierCalculated, NULL, THREAD_NUM + 1);
	for (i = 0; i < THREAD_NUM; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &rollDice, a) != 0)
			perror("Failed to create thread");
	}
	pthread_barrier_wait(&barrierRolledDice);
	max = 0;
	for (i = 0; i< THREAD_NUM; i++)
	{
		if (diceValues[i] > max)
			max = diceValues[i];
	}
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (diceValues[i] == max)
			status[i] = 1;
		else
			status[i] = 0;
	}
	pthread_barrier_wait(&barrierCalculated);
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
	pthread_barrier_destroy(&barrierRolledDice);
	pthread_barrier_destroy(&barrierCalculated);
	return 0;
}