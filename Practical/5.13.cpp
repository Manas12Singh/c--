#include <iostream>
using namespace std;
class Toolbooth
{
    unsigned noOfCars;
    double moneyCollected;
public:
    Toolbooth() : noOfCars(0), moneyCollected(0) {}
    void payingCar()
    {
        noOfCars++;
        moneyCollected += 50;
    }
    void nonPayingCar()
    {
        noOfCars++;
    }
    void display()
    {
        cout << "Total no of cars: " << noOfCars << endl;
        cout << "Total amount collected: " << moneyCollected << endl;
    }
};
int main()
{
    Toolbooth t1;
    cout << "Options:\n1. Paying Car.\n2. Non-Paying Car.\n3. Display Total\n4. Exit\n";
    while (1)
    {
        int opt;
        cout << "Enter your choice(1 to 4): ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            t1.payingCar();
            break;
        case 2:
            t1.nonPayingCar();
            break;
        case 3:
            t1.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Wrong Choice.\n";
        }
    }
    return 0;
}