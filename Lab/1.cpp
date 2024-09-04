#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int nums[], int target, int i, int n)
{
    if (i == n)
    {
        cout << "Not found" << endl;
        return i;
    }
    if (nums[i] == target)
    {
        cout << "Found at index " << i << endl;
        return i + 1;
    }
    return linearSearch(nums, target, i + 1, n);
}

int binarySearch(int nums[], int target, int l, int r)
{
    if (l > r)
    {
        cout << "Not found" << endl;
        return 0;
    }
    int mid = (l + r) / 2;
    if (nums[mid] == target)
    {
        cout << "Found at index " << mid << endl;
        return 1;
    }
    if (nums[mid] > target)
        return binarySearch(nums, target, l, mid) + 1;
    return binarySearch(nums, target, mid + 1, r) + 1;
}

int frequencySearch(int nums[], int target, int n)
{
    int l = 0, r = n - 1, l1 = -1, r1 = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target))
        {
            l1 = mid;
            break;
        }
        if (nums[mid] >= target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l1 == -1)
        return 0;
    l = l1, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target && (mid == n - 1 || nums[mid + 1] != target))
        {
            r1 = mid;
            break;
        }
        if (nums[mid] <= target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r1 - l1 + 1;
}

void bubbleSort(int nums[], int i, int n)
{
    if (n == 1 || i == n - 1)
        return;
    if (nums[i] > nums[i + 1])
        swap(nums[i], nums[i + 1]);
    bubbleSort(nums, i + 1, n);
    if (i == 0)
        bubbleSort(nums, 0, n - 1);
}

void selectionSort(int nums[], int i, int j, int &k, int n)
{
    if (i == n || j == n)
        return;
    if (nums[j] < nums[k])
        k = j;
    selectionSort(nums, i, j + 1, k, n);
    if (i == j)
    {
        if (i != k)
            swap(nums[i], nums[k]);
        k = i + 1;
        selectionSort(nums, k, k, k, n);
    }
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0)
    {
        int n, target, c;
        cout << "Enter the length of array: ";
        cin >> n;
        int nums[n];
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << "Enter target: ";
        cin >> target;
        c = frequencySearch(nums, target, n);
        cout << "No of comparisons: " << c << endl;
        // cout << "Frequency: " << c << endl;
        int k = 0;
        selectionSort(nums, 0, 0, k, n);
        cout << "Sorted array: ";
        for (auto &i : nums)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// given a sorted array of +ve integers containing few duplicate elements design an algorithm and implement it using a program to find whether the key element is present in an array or not. if present, then find the no of copies of the given key.

// given an array of non-negative integers. design an algo and program to count number of pair of integer such that their diff is equal to a given key

// find wether given key element is present in an array or not, also find number of compariosons for each input case. O(n)