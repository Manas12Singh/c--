#include <bits/stdc++.h>

using namespace std;

int minimumWaterRemoved(vector<int> &buckets)
{
    sort(buckets.begin(), buckets.end());
    int n = buckets.size();
    int l = 0, r = n - 1, c = 1;
    int res = 0;
    while (l < r)
    {
        if (buckets[l] < buckets[r] - buckets[r - 1])
            res += buckets[l++];
        else
            res += (buckets[r--] - buckets[r]) * (c++);
    }
    return res;
}

int main()
{
    vector<int> buckets = {0, 1, 2, 2, 4, 8, 8, 8, 9};
    cout << minimumWaterRemoved(buckets) << endl;
    return 0;
}