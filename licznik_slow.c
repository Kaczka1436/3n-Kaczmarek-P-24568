#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	unsigned long licznik = 0;
	FILE *wp;
	int ch;

	if(argc != 2)
	{
		fprintf(stderr, "Zly numer parametru ziomus\n");
		return 1;
	}

	wp = fopen(argv[1], "r");
	if(wp == NULL)
	{
		perror("Blad koleszko");
		return 1;
	}

	while((ch = fgetc(wp)) != EOF)
	{
		fputc(ch, stdout);
		licznik++;
	}
	fclose(wp);
	printf("\nPlik %s zawiera %lu znakow", argv[1], licznik);

	return 0;
}
