#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>

#define BUFOR 50

int main(int argc, char * argv[])
{
	int plik;
	char BUFF[BUFOR];

	if(argc !=2 || strcmp(argv[1], "--help")== 0)
	{
		printf("Uzywam: %s plik.\n", argv[0]);
		return 1;
	}

	if(!(plik = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644)))
	{
		printf("Blad otwarca pliku!\n");
		return 2;
	}

	int i=0;
	for(;i<10;i++)
	{
		sprintf(BUFF, "%d\n", rand()%100);
		write(plik, &BUFF, strlen(BUFF));
	}


	if(close(plik) == -1)
	{
		printf("Blad zamkniecia pliku!\n");
		return 2;
	}
	return 0;
}
