#include "threads.h"

// to solve race condition problem we need to use a lock
int x = 0;
pthread_mutex_t mutex;

void *routine(void *)
{
	for(int i =0 ; i < 10000000; i++){
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("x = %d \n", x);
}