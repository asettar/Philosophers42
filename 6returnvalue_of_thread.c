#include "threads.h"

int x = 0;

//you can get the return value of a thread using second argument in pthread join

void *routine(void )
{
	int *p = malloc(sizeof(int));
	*p = 4;
	return (void*)p;
}
    
int main(int ac, char **argv)
{
	pthread_t t1, t2;
	int *res;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, (void**)&res);
	printf("%d ", *res);
}
