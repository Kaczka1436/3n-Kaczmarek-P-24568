#include <stdio.h>
#include <errno.h>

int main(void)
{
	FILE *wp;
	char word[41];

	wp = fopen("slowa.txt", "a+");
	if(wp == NULL ) // if(!wp)
	{
		perror("fopen");
		return 1;
	}
	puts("Wpisz jakies slowa zeby dodac je do pliku");
	puts("Na koncu dodaj #\n");

	while((fscanf(stdin, "%40s", word) == 1) && (word[0] != '#'))
	{
		fprintf(wp, "%s",word);
		fprintf(wp, "%s"," ");
	}
	puts("Zawartosc pliku: ");
	rewind(wp);
	while(fscanf(wp, "%s", word) == 1)
	{
		printf("%s\n", word);
	}


	puts("DONE!\n");
	if(fclose(wp)!=0){
		perror("Blad zamkniecia pliku\n");
		return 2;
	}
	return 0;

}
