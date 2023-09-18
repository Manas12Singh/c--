#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr, int end)
{
    int start = 0;
    while (start < end)
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the number of position to be rotate: ";
    cin >> k;
    reverse(arr, n - 1);
    reverse(arr, k % n - 1);
    reverse(arr + k % n, n - (k % n) - 1);
    cout << "Rotated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}