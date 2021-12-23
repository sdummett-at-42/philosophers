
#include "philosophers.h"
#include <errno.h>

void *routine(void *arg)
{
	pthread_mutex_t	mutex = *(pthread_mutex_t *)arg;
	pthread_mutex_lock(&mutex);
	sleep(2);
	pthread_mutex_unlock(&mutex);
}
int main()
{
	pthread_t 		th;
	pthread_mutex_t	mutex;

	pthread_create(&th, NULL, routine, &mutex);
	if (pthread_mutex_lock(&mutex) == EDEADLK)
	{
		printf("DEADLOCK\n");
	}
	else{
		printf("NOT DEADLOCK\n");
	}

	pthread_join(th);
	return 0;
}