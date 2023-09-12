#include <iostream>
#include <cmath>

using namespace std;

void calculateArea(int length, int breadth)
{
    cout << "Area of Rectangle: " << length * breadth << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "Options: " << endl
             << "1. Area of Triangle" << endl
             << "2. Area of Circle" << endl
             << "3. Area of Rectangle" << endl
             << "4. Area of Square" << endl
             << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }
    } while (choice != 5);
    return 0;
}
