#include <iostream>
using namespace std;
template <typename T>
T findMax(T arr[])
{
    int n = size(arr);
    T max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int arr1[] = {1, 5, 3, 9, 2};
    double arr2[] = {1.5, 3.2, 2.7, 4.8};
    int maxInt = findMax(arr1);
    cout << "Maximum element in the integer array: " << maxInt << endl;
    double maxDouble = findMax(arr2);
    cout << "Maximum element in the double array: " << maxDouble << endl;
    return 0;
}
