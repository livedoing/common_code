#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stddef.h>

int main(int argc, char* argcv[]) {

    if (fork() == 0) {
        std::cout << "sub" << std::endl;
        sleep(10);
        std::cout << "sub end" << std::endl;
        exit(0);
    } else {
        std::cout << "father" << std::endl;
        sleep(20);
        wait(nullptr);
        std::cout << "wait end" << std::endl;
        sleep(100);
    }

    return 0;
}

