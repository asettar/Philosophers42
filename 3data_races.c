#include "threads.h"

// data race happens when can be some data corruption between threads resulting in an undefined behaviours
// threads can read some vlue then paused letting other thread to complete executing
// to solve this issue to have to use mutex : next
int x = 0;
void	*routine(void *)
{
	for(int i = 0; i < 100000000; i++)
		x++;
}

int main()
{
	c
	printf("x = %d \n", x); // x value might no give the one that you expect bc of possible data race
}