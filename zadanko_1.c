#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFF 1

int main(int argc, char *argv[])
{
	int pierwszy, ostatni;
	char *nazwapliku;
	ssize_t ret_in, ret_out;
	char BUFOR[BUFF];

	if(argc !=2 || strcmp(argv[1], "--help") == 0){
		printf("Uzycie: %s nazwapliku.txt\n", argv[0]);
		return 1;
	}
	else
	{
		nazwapliku = argv[1];
	}
	if(!(pierwszy = open(nazwapliku, O_RDONLY)))
	{
		printf("Blad otwarcia pliku: %s\n", nazwapliku);
		return 2;
	}
	else
	{
		printf("Otworzylem go: %s\n", nazwapliku);
	}
	if(!(ostatni = open(strcat(nazwapliku, ".red"), O_WRONLY | O_CREAT | O_TRUNC, 0644)))
	{
		printf("Blad otwarcia lub utworzenia pliku: %s\n", nazwapliku);
		return 2;
	}
	else
	{
	printf("Udalo sie otworzyc: %s\n", nazwapliku);
	}
	int i=0;
	while ((ret_in = read(pierwszy, &BUFOR, BUFF)) > 0)
	{
	if(!(i%3))
		{
		ret_out = write(ostatni, &BUFOR, (size_t)ret_in);
		}
		i++;
	}

	write(ostatni, "\n", 1);

	if(close(pierwszy) == -1 || close(ostatni) == -1)
	{
		printf("Blad zamkniecia pliku\n");
		return 1;
	}

	return 0;

}
