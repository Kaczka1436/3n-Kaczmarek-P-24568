#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

        int input_fd, output_fd;
        char buffer[BUFFER_SIZE];
        ssize_t ret_in, ret_out;

        if(argc !=3 || strcmp(argv[1], "--help")==0)
        {
                printf("Usage: %s file_origin file_destinatio\n", argv[0]);
        }



        //open file for reading;
        input_fd= open(argv[1], O_RDONLY);
        if(input_fd == -1)
        {
                perror("open");
                return 2;
        }

        //Open file for writing (destination);
        output_fd= open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(output_fd == -1)
        {
                perror("write");
                return 3;
        }

        //Copy;
        while((ret_in = read(input_fd, &buffer, BUFFER_SIZE)) > 0)
        {
                ret_out = write(output_fd, &buffer, ret_in);
                if(ret_out != ret_in)
                {
                        printf("Write error\n");
                        return 5;
                }
        }


        close(input_fd);
        close(output_fd);

        return 0;
}

