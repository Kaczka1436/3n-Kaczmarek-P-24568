/*
Author: Patryk Kaczmarek
ver. 1.0.0.
Date: 3.07.2020r.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]){
	pid_t pid;
	int licznik;
	int fd;
	int wynik;
	char bufor[1];
	FILE *plik;
	int status;

	if(argc!=3)
	{
		perror("Enter 2 values!!\n");
		return 1;
	}
	pid = fork();

	if(pid == -1)
	{
		perror("Fork fault\n");
		return 2;
	}
	if(pid == 0)
	{
		fd= open(argv[2], O_RDONLY);
		if(fd == -1)
		{
			perror("open fault\n");
			return 3;
		}
	while(read(fd,&bufor,1)==1)
	{
		licznik++;
	}
	plik = fopen(argv[1],"w");
	if(plik == NULL)
	{
		perror("Open first element fault\n");
		return 4;
	}
	fprintf(plik, "Plik %s ma wielkosc: %d bajtow\n", argv[2], licznik);

	if(licznik >= 100)
	{
		wynik = 10;
	}
	else
	{
		wynik = -1;
	}
	printf("Return: %d \n",wynik);

	close(fd);
	if(fclose(plik) == EOF)
	{
		fprintf(stderr, "fclose fault\n");
		return 5;
	}
}
	if(pid>0)
	{
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("Program end.\n Exit status: %d \n",WEXITSTATUS(status));
	}
}
	return 0;
}
