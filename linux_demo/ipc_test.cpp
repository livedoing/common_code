#include <iostream>
#include <sys/ipc.h>

int main(int argc, char* argv[]) {
    key_t k = ftok("./ipc_test.cpp", 3);
    std::cout << k << std::endl;

    key_t k_2 = ftok("./ipc_test.cpp", 3);
    std::cout << k << std::endl;
    return 0;
}