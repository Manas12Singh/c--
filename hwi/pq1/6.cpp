#include <bits/stdc++.h>

using namespace std;

int maxExpert(vector<int> A)
{
    int n = A.size();
    int size = 0;
    for (int i : A)
        size = max(size, i);
    // max valid element to find expert number is min of size of array and max element in array
    size = min(n, size);

    // vector to sort ranges having 0 to i valued elements
    vector<vector<pair<int, int>>> m(size + 1);

    // currently sorting its position(s) as range(s)
    for (int i = 0; i < n; i++)
        m[A[i]].push_back({i, i});
    int res = 0, pcount = m[0].size();
    int maxToGo = n;
    for (int i = 1; i <= size; i++)
    {
        // if previous level as no valid range break
        // as no new updation will increase the expert value of the subarray
        if (pcount == 0)
            break;
        int count = 0;
        auto cit = m[i].begin();
        auto pit = m[i - 1].begin();
        while ( count < pcount && cit != m[i].end() && pit != m[i - 1].end(),)
        {
            if (pit + 1 == m[i - 1].end() || (pit + 1)->first > cit->first)
            {
                cout << pit->first << " " << pit->second << endl;
                cout << cit->first << " " << cit->second << endl;
                cit->first = min(pit->first, cit->first);
                cit->second = max(pit->second, cit->second);
                cout << cit->first << " " << cit->second << endl;
                cit++;
                count++;
            }
            pit++;
        }
        if (i > 1 && cit != m[i].end())
        {
            maxToGo = min(maxToGo, cit->first);
        }
        cout << pcount << " " << count << endl;
        cout << endl;
        res += i * max(pcount - count, 0);
        pcount = count;
    }
    return res + pcount * (size + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i : A)
        cin >> i;
    cout << maxExpert(A) << endl;
}