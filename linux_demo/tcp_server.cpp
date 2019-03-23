#include<iostream>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "./a.out ip" << std::endl;
        return -1;
    }
    int listen_fd;
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd <= 0) {
        std::cout << "socket failed" << std::endl;
        return -1;
    }

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(1234);
    int ret = bind(listen_fd, (const sockaddr*)(&servaddr), sizeof(servaddr));
    if (ret != 0) {
        std::cout << "bind failed" << std::endl;
        return -1;
    }
    ret = listen(listen_fd, 100);
    if (ret != 0) {
        std::cout << "bind failed" << std::endl;
        return -1;
    }

    if (fork() > 0) {
        struct sockaddr addr;
        socklen_t len;
        ret = accept(listen_fd, &addr, &len);
        if (ret != 0) {
            std::cout << "accept failed" << std::endl;
            return -1;
        }
        while(true) {
            sleep(1);
        }
    }
struct sockaddr addr;
socklen_t len;
        ret = accept(listen_fd, &addr, &len);
        if (ret != 0) {
            std::cout << "accept failed" << std::endl;
            return -1;
        }
    while(true) {
        sleep(1);
    }


    return 0;
}