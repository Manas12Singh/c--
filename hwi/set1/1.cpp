#include <bits/stdc++.h>
#define L long long
using namespace std;

L peak_element(vector<L> &nums)
{
    L n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;
    L l = 1, r = n - 2;
    while (l <= r)
    {
        L mid = l + (r - l) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid - 1] >= nums[mid])
            r = mid - 1;
        else if (nums[mid] <= nums[mid + 1])
            l = mid + 1;
    }
    return -1;
}

int main()
{
    L n;
    cin >> n;
    vector<L> nums(n);
    for (L &i : nums)
        cin >> i;
    cout << peak_element(nums) << endl;
    return 0;
}
