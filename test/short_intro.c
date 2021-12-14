
#include "philosophers.h"
#define THREAD_NUMBERS 2

int fuel = 0;
pthread_mutex_t mutex_fuel;
pthread_cond_t	condFuel;

void *fuel_fillin(void *arg){
	printf("Filling fuel\n");
	for (int i = 0; i < 5; i++){
		pthread_mutex_lock(&mutex_fuel);
		fuel += 15;
		printf("Filled fuel... %d\n", fuel);
		pthread_mutex_unlock(&mutex_fuel);
		pthread_cond_signal(&condFuel);
		sleep(1);
	}
}

void *car(void *arg){
	printf("Here to get fuel\n");
	pthread_mutex_lock(&mutex_fuel);
	while (fuel < 40)
	{
		printf("No fuel. Waiting...\n");
		pthread_cond_wait(&condFuel, &mutex_fuel);
	}
	fuel -= 40;
		printf("Got fuel. Now left: %d\n", fuel);
	pthread_mutex_unlock(&mutex_fuel);
	
}

int main(void)
{
	pthread_t th[THREAD_NUMBERS];
	
	pthread_mutex_init(&mutex_fuel, NULL);
	pthread_cond_init(&condFuel, NULL);
	// int i = 0;
//	for (int i = 0; i < THREAD_NUMBERS; i++)
	pthread_create(&th[0], NULL, &fuel_fillin, NULL);
	pthread_create(&th[1], NULL, &car, NULL);
//	for (int i = 0; i < THREAD_NUMBERS; i++)
	pthread_join(th[0], NULL);
	pthread_join(th[1], NULL);
	
	pthread_mutex_destroy(&mutex_fuel);
	// printf("Number of mails: %d\n", mails);
}