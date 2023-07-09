#include "threads.h"

pthread_mutex_t mutex;
int x = 0;
// if you create then join in for loop , you're program will wait for each thread to finish exectuing before crating another one
// wich we dont want we wnt thread to be run in parallel, so we should make the cration 
// in the first for then in the scnd for we o the join
void *routine(void *)
{
	for(int i =0 ; i < 10000000; i++){
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int ac, char **argv)
{
	pthread_t th[4];
	int i;
	pthread_mutex_init(&mutex, NULL);
	// for(int i = 0; i < 4; i++)
	// {
	// 	pthread_create(th + i, NULL, &routine, NULL);
	// 	printf("Thread %d has started\n", i + 1);
	// 	pthread_join(th[i], NULL);
	// 	printf("Thread %d has finished\n", i + 1);
	// }
	for(int i = 0; i < 4; i++)
	{
		pthread_create(th + i, NULL, &routine, NULL);
		printf("Thread %d has started\n", i + 1);
	}
	for(int i = 0; i < 4; i++)
	{
		pthread_join(th[i], NULL);
		printf("Thread %d has finished\n", i + 1);
	}
}