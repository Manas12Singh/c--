#include <iostream>
#include <vector>
using namespace std;

class List
{
    vector<int> v1;

public:
    List(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
            v1.push_back(arr[i]);
    }
    void put_data()
    {
        for (int i = 0; i < v1.size(); i++)
            cout << v1.at(i) << " ";
        cout << endl;
    }
    friend void operator<<(List &, int);
    friend void operator>>(List &, int);
};

void operator<<(List &l, int num)
{
    l.v1.push_back(num);
}

void operator>>(List &l, int num)
{
    l.v1.insert(l.v1.begin(), num);
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    List l1(a, 5);
    l1.put_data();
    l1 << 6;
    l1 >> 5;
    l1.put_data();
    return 0;
}
