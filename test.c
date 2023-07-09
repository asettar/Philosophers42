



#include "philo.h"

#define N 5

void* routine(void* data)
{
	// usleep(1000);
	while (true)
	{
		printf("%d\n", *(int*)data);
	*(int*)data += 1;
	sleep(1);
	}
	return (NULL);
}

int main()
{
	pthread_t tid[N];
	int data[N] = {1, 3, 4, 5, 6};
	for (int i = 0; i < N; i++)
		pthread_create(&tid[i], NULL, routine, &data[i]);
	for (int i = 0; i < N; i++)
		pthread_detach(tid[i]);
	// for (int i = 0; i < N; i++)
	// 	pthread_join(tid[i], NULL);
	while (true)
	{
		for (int i=0; i < N; i++)
		{
			if (data[i] == 10)
			{
				printf("died %d\n", i);
				exit(0);
			}
		}
	}
}