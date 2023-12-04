#include <iostream>
double readDoubleFromKeyboard()
{
    double number;
    std::cin >> number;
    if (std::cin.fail())
    {
        throw std::runtime_error("Invalid input.");
    }
    return number;
}
double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return numerator / denominator;
}
int main()
{
    try
    {
        std::cout << "Enter the first number: ";
        double num1 = readDoubleFromKeyboard();
        std::cout << "Enter the second number: ";
        double num2 = readDoubleFromKeyboard();
        double result = divideNumbers(num1, num2);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
