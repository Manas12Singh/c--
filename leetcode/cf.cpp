#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_set<int> s0,s1;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if(y)
                s1.insert(x);
            else
                s0.insert(x);
        }
        int res=0;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s0.size();j++){
                res+=abs(i-j);
            }
        }
    }
    return 0;
}