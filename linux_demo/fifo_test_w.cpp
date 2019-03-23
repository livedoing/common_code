#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (mkfifo("./file_fifo", 0666) < 0 && errno != EEXIST) {
        std::cout << "create fifo failed" << std::endl;
        return -1;
    } else {
        char cont_w[] = "Iam FIFO write.";
        char cont_r[255];
        int fd = open("./file_fifo", O_CREAT|O_RDWR, 0666);
        std::cout << "open end" << std::endl;
        if (fd > 0) {
            while(1) {
                write(fd, cont_w, strlen(cont_w));
                std::cout << "write: " << cont_w << std::endl;
                sleep(5);

                read(fd, cont_r, 255);
                std::cout << "read: " << cont_r << std::endl;
         }
            close(fd);
        }
    }

    return 0;
}

