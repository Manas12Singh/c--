#include <iostream>
using namespace std;

int main()
{
    int matrix1[3][3], matrix2[3][3], result[3][3] = {0};
    cout << "Enter the elements of matrix 1: " << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> matrix1[i][j];
    cout << "Enter the elements of matrix 2: " << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> matrix2[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
    cout << "Result: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}