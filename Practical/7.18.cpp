#include <iostream>
#include <cmath>
using namespace std;
class Float
{
public:
    virtual float calculateSquare(float num) = 0;
    virtual float calculateCube(float num) = 0;
};
class Square : public Float
{
public:
    float calculateSquare(float num)
    {
        return num * num;
    }
    float calculateCube(float num)
    {
        return 0.0;
    }
};
class Cube : public Float
{
public:
    float calculateSquare(float num)
    {
        return 0.0;
    }
    float calculateCube(float num)
    {
        return num * num * num;
    }
};
int main()
{
    float number;
    cout << "Enter a number: ";
    cin >> number;
    Square square;
    Cube cube;
    float squareResult = square.calculateSquare(number);
    cout << "Square of " << number << " is: " << squareResult << endl;
    float cubeResult = cube.calculateCube(number);
    cout << "Cube of " << number << " is: " << cubeResult << endl;
    return 0;
}
