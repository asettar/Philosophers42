#include "threads.h"

//what is the difference between threads and pipes

// threads share memory (system resources) while processes are not they duplicate memory
int x = 2;
void	*routine1(void *)
{
	x++;
	sleep(1); //because threads are executed parrallel can be not take effect
	printf("value of x is : %d\n", x);
}

void	*routine2(void *)
{
	// x++;
	sleep(1);
	printf("value of x is : %d\n", x);
}

int main()
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine1, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
		return 1;
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
}