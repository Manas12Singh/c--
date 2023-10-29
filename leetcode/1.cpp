#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int l1 = a.length() - 1;
        int l2 = b.length() - 1;
        int c = 0;
        string sum;
        while (l1 >= 0 || l2 >= 0 || c > 0)
        {
            int d = c;
            if (l1 >= 0)
                d += a[l1--] - '0';
            if (l2 >= 0)
                d += b[l2--] - '0';
            c = d / 2;
            d %= 2;
            sum.push_back(d + '0');
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};