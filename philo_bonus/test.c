
#include "philosophers_bonus.h"

int *fuel;
sem_t semaphore;

void	*routine(void *arg)
{
	// sem_wait(&semaphore);
	*fuel += 50;
	printf("Current value is %d\n", *fuel);
	sem_post(&semaphore);
	return NULL;
}

int main(void)
{
	pthread_t th[4];
	fuel = malloc(sizeof(int));

	*fuel = 50;
	sem_init(&semaphore, 0, 1);
	for (int i = 0; i < 4; i++){

		pthread_create(&th[i], NULL, routine, NULL);
	}
	// sem_wait(&semaphore);
	printf("Deallocating fuel\n");
	free(fuel);
	// for(int i = 0; i < 4; i++){
	// 	pthread_join(th[i], NULL);
	// }
	sem_destroy(&semaphore);
}