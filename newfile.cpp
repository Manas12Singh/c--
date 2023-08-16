#include <iostream>

using namespace std;

void sort(int array[], int number);

int main()
{
    int ar[8] = {2,1,3, 6, 99,54,5,0};
    sort(ar,8);
}

void sort(int array[], int number)
{
    for (int i = 0; i < number - 1; i++)
    {
        int mindex = i;
        for (int j = i+1; j < number;j++)
        {
            if (array[j] < array[mindex])
            {
                mindex = j;
            }
        }
        // int s = array[i];
        // array[i] = array[mindex];
        // array[mindex] = s;
        swap(array[i],array[mindex]);
    }

    for (int k = 0; k < number ; k++)
    {
        cout << array[k]<<" ";
    }
}