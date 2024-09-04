#include <iostream>
using namespace std;
class Point
{
private:
    int x;
    int y;
public:
    void setPoint(int xValue, int yValue)
    {
        x = xValue;
        y = yValue;
    }
    void getPoint(int &xValue, int &yValue)
    {
        xValue = x;
        yValue = y;
    }
};
int main()
{
    Point p;
    p.setPoint(28, 35);
    int x, y;
    p.getPoint(x, y);
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    return 0;
}
