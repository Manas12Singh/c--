#include <iostream>
#include <iomanip>

int main()
{
    int b = -100;
    float a = *(float *)&b;
    int *intPtr = reinterpret_cast<int *>(&a);

    std::cout << "Value of float a: " << a << std::endl;

    // Display the binary representation of the float's memory
    std::cout << "Binary representation of a in memory: ";
    for (int i = sizeof(float) * 8 - 1; i >= 0; --i)
    {
        std::cout << ((*intPtr >> i) & 1);
    }
    std::cout << std::endl;

    return 0;
}
