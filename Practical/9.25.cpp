#include <iostream>
using namespace std;
class Stack
{
private:
    int data[2];
    int top;
public:
    class FULL
    {
    };
    class EMPTY
    {
    };
    Stack() : top(-1) {}
    void push(int value)
    {
        if (top >= 1)
        {
            throw FULL();
        }
        data[++top] = value;
    }
    int pop()
    {
        if (top < 0)
        {
            throw EMPTY();
        }
        return data[top--];
    }
};
int main()
{
    Stack s;
    int choice, value;
    do
    {
        try
        {
            cout << "Menu:\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                s.push(value);
                cout << "Value pushed successfully.\n";
                break;
            case 2:
                cout << "Popped value: " << s.pop() << endl;
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }
            cout << endl;
        }
        catch (const Stack::FULL)
        {
            cerr << "Error: Stack is full.\n";
        }
        catch (const Stack::EMPTY)
        {
            cerr << "Error: Stack is empty.\n";
        }
    } while (choice != 3);
    return 0;
}
