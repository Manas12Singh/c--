#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> monster(n);
    for (int i = 0; i < n; i++)
        cin >> monster[i].first;
    for (int i = 0; i < n; i++)
        cin >> monster[i].second;
    sort(monster.begin(), monster.end());
    int i = 0;
    while (i < n && monster[i].first <= e)
    {
        e += monster[i].second;
        i++;
    }
    cout << i << endl;
}