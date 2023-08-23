#include <iostream>
#include <iomanip>

int main() {
    long c = -100;
    float* floatPtr = reinterpret_cast<float*>(&c);
    
    std::cout << "Value of long c: " << c << std::endl;
    
    // Display the binary representation of the long's memory
    std::cout << "Binary representation of c in memory: ";
    for (int i = sizeof(long) * 8 - 1; i >= 0; --i) {
        std::cout << ((c >> i) & 1);
    }
    std::cout << std::endl;
    
    return 0;
}
