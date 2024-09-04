#include <iostream>
using namespace std;

double area(double base, double height)
{
    return 0.5 * base * height;
}

float area(float length, float breadth)
{
    return length * breadth;
}

double area(double radius)
{
    return 3.14 * radius * radius;
}

float area(float side)
{
    return side * side;
}

int main()
{
    int choice;
    cout << "Options: " << endl
         << "1. Area of Triangle" << endl
         << "2. Area of Circle" << endl
         << "3. Area of Rectangle" << endl
         << "4. Area of Square" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        double base, height;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
        cout << "Area: " << area(base, height) << " sq. units" << endl;
        break;
    case 2:
        double radius;
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Area: " << area(radius) << " sq. units" << endl;
        break;
    case 3:
        float length, breadth;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter breadth: ";
        cin >> breadth;
        cout << "Area: " << area(length, breadth) << " sq. units" << endl;
        break;
    case 4:
        float side;
        cout << "Enter side: ";
        cin >> side;
        cout << "Area: " << area(side) << " sq. units" << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
    }
    return 0;
}
