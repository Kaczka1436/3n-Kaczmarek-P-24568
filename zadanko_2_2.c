#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) 
{
	int plik;

	if(argc !=2 || strcmp(argv[1], "--help") == 0)
	{
		printf("Uzywam: %s\n", argv[0]);
		return 1;
	}
	if(!(plik = open(argv[1], O_RDONLY)))
	{
		printf("Blad otwarca pliku!\n");
		return 2;
	}

	char c;
	int current = 0;
	while (read(plik, & c, 1)>0)
	{
	if(c!= '\n')
	{
	current = current*10;
	current += (int) c - 48;
	}
	else
	{
		printf("%d\n", current*3);
		current = 0;
		}
	}
	if(current != 0)
	{
		printf("%d\n", current);
	}

	if(close(plik) == -1)
	{
		printf("blad otwarcia pliku\n");
		return 2;
	}
	return 0;
}
