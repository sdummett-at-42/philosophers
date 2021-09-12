/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 15:59:34 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/12 16:06:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_test.h"

int mails = 0;

void *routine()
{
	for (int i = 0; i < 100000; i++)
		mails++;
	return NULL;
}

int main()
{
	pthread_t p1, p2;

	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		perror("Failed to create thread");
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		perror("Failed to create thread");
	if (pthread_join(p1, NULL) != 0)
		perror("Failed to join thread");
	if (pthread_join(p2, NULL) != 0)
		perror("Failed to join thread");
	printf("Number of mails: %d\n", mails);
}