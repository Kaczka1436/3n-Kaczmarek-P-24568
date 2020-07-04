#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
        pid_t pid;
        if((pid = fork()) == -1)
        {
                printf("Nie udalo sie stworzyc dziecka\n");
                exit(1);
        }

        if(pid == 0)
        {
        if(execl("/bin/ls","ls","-l", NULL) == -1)//komenda ls -l
        {
                fprintf(stderr, "Nie mozna uruchomic exec\n");
        }
        exit(0);
        }
        int status_dziecka;
        wait(&status_dziecka);
        if(status_dziecka != 0)
        {
                printf("Proces dziecka ma blad\n");
                exit(1);
        }
        printf("Proces dziecka nie ma bledu\n");
        return 0;
}
