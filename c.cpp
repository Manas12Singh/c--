#include <iostream>
using namespace std;

class rev
{
    public:
    int n;
    int rev=0;
    void input()
    {
        cin >> n;
    }
    void backward()
    {
        int ldigit=n;
        while(ldigit>0)
        {
            rev=rev*10+ldigit;
        }
    }
    void display()
    {
        cout << rev;
    }
};

int main()
{
    rev obj;
    obj.input();
    obj.backward();
    obj.display();
    return 0;
}
