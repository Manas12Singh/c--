#include <iostream>
using namespace std;

class student
{
public:
    static int count;
    void student()
    {
        count++;
    }
};