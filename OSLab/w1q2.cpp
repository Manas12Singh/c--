#include <unistd.h>
#include <iostream>

int main() {
    int p = fork();
    if (p > 0) {
        std::cout << "Process ID: " << getpid() << std::endl;
        std::cout << "Process ID of child: " << p << std::endl;
    } else if (p == 0) {
        std::cout << "Process ID: " << getpid() << std::endl;
        std::cout << "Process ID of parent: " << getppid() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
