#include <iostream>
#include <iomanip>

int main() {
    int b = -100;
    float* floatPtr = reinterpret_cast<float*>(&b);
    
    std::cout << "Value of integer b: " << b << std::endl;
    
    // Display the binary representation of the integer's memory
    std::cout << "Binary representation of b in memory: ";
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        std::cout << ((b >> i) & 1);
    }
    std::cout << std::endl;
    
    return 0;
}
