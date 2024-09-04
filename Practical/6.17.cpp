#include <iostream>
#include <vector>
using namespace std;
class List
{
    vector<int> arr;
public:
    friend void operator<<(ostream &, List &);
    friend void operator>>(istream &, List &);
};
void operator<<(ostream &st, List &l)
{
    for (auto &&i : l.arr)
        cout << i << " ";
    cout << endl;
}
void operator>>(istream &st, List &l)
{
    int a;
    cin >> a;
    l.arr.push_back(a);
}
int main()
{
    int n;
    List l1;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> l1;
    cout << "Elements are: " << l1;
    return 0;
}
