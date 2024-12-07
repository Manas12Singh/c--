#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int p = fork();
    if (p == 0) {
        cout << "Child: Process id: " << getpid() << endl;
        cout << "Process id of parent: " << getppid() << endl;
    } else if (p > 0) {
        cout << "Parent: Process id: " << getpid() << endl;
        cout << "Process id of child: " << p << endl;
    } else {
        cout << "Fork failed." << endl;
    }
    cout << endl;
    return 0;
}