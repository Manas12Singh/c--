#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int k = 0, l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= n - mid) {
            k = n - mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << k << endl;
    return 0;
}