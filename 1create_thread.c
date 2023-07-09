#include <threads.h>

void	*routine(void *)
{
	printf("KKKKKKK\n");
}
int main(int ac, char **argv)
{
	pthread_t t1;    // threads ids, just an unsigned long
	pthread_create(&t1, NULL, &routine, NULL); // if success creation it will return 0 
	pthread_join(t1, NULL); // wait till finishing the execution of the thread, if success it will return 0
}