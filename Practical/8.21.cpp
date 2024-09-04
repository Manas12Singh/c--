#include <iostream>
#include <algorithm>
using namespace std;
typedef void (*SortFunction)(int[], int);
class Sorter
{
public:
    virtual void sort(int arr[], int size) = 0;
};
class DescendingSorter : public Sorter
{
public:
    void sort(int arr[], int size) override
    {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (arr[j] < arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
};
class AscendingSorter : public Sorter
{
public:
    void sort(int arr[], int size) override
    {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
};
int main()
{
    int arr[] = {5, 2, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    Sorter *descendingSorter = new DescendingSorter();
    descendingSorter->sort(arr, size);
    cout << "Descending order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Sorter *ascendingSorter = new AscendingSorter();
    ascendingSorter->sort(arr, size);
    cout << "Ascending order: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete ascendingSorter;
    return 0;
}
