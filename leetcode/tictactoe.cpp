#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class gameState
{
private:
    vector<vector<char>> matrix;
    int move;

public:
    gameState()
    {
        matrix = vector<vector<char>>(3, vector<char>(3, ' '));
        move = 0;
    }
    gameState(gameState &t)
    {
        matrix = t.matrix;
        move = t.move;
    }
    vector<vector<char>> getMatrix()
    {
        return matrix;
    }
    // return true, if valid update, otherwise false
    bool update(int x, int y, char c)
    {
        if (x < 0 || y < 0 || x > 2 || y > 2 || matrix[x][y] != ' ')
        {
            cerr << "Invalid Input!!" << endl;
            return false;
        }
        else
        {
            matrix[x][y] = c;
            move++;
            return true;
        }
    }
    void printState()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    char checkWinner()
    {
        for (int i = 0; i < 3; i++)
            if(row[])
    }
};

int main()
{
    gameState g1;
    g1.update(0, 0, 'X');
    gameState g2(g1);
    g1.update(1, 1, 'O');
    g1.printState();
    g2.printState();
    g1.update(-1, 1, 'O');
    g1.printState();
    return 0;
}
