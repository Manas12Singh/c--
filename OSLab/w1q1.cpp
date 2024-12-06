#include <unistd.h>
#include <iostream>

int main() {
    int p = fork();

    if (p == 0) {
        std::cout << "Child process" << std::endl;
    } else if (p > 0) {
        std::cout << "Parent process" << std::endl;
        std::cout << "Child ID: " << p << std::endl;
    } else {
        std::cout << "Fork failed" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
