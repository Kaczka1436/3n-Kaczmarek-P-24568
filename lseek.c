#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>


int randomRange(int, int);

int main(int argc, char *argv[])
{
	const int low = 0;
	const int up = 10;
	
	srand(time(0));
	
	int r_num = randomRange(low, up);
	printf("Generated numer: %d\n", r_num);
	
	return 0;
}

int randomRange(int lower, int upper)
{
	int num, input_fd, output_fd;
	num = (rand() % (upper - lower + 1) +lower);
	return num;
}