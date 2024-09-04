#include <iostream>
using namespace std;

class Sum
{
    int num;

public:
    Sum(int num)
    {
        this->num = num;
    }
    Sum(Sum &a)
    {
        this->num = a.num;
    }
    
};