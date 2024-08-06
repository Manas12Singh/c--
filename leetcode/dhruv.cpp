#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    void print(vector<vector<int>> &vn)
    {
        for (auto it : vn)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }
        cout << endl;
    }
    void ill(int i, int j, vector<vector<int>> &vn)
    {
        int n = vn.size();
        for (int k = 0; k < n; k++)
        {
            vn[k][j]++;
            vn[i][k]++;
        }
        for (int k = 1; k < n - 1; k++)
        {
            if (i - k >= 0 && j - k >= 0)
                vn[i - k][j - k]++;
            if (i + k < n && j + k < n)
                vn[i + k][j + k]++;
            if (i - k >= 0 && j + k < n)
                vn[i - k][j + k]++;
            if (i + k < n && j - k >= 0)
                vn[i + k][j - k]++;
        }
    }
    void help(vector<vector<int>> &vn, vector<int> &r, vector<vector<int>> &l, int i, int j, int n, int f)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || !f)
            return; // f only allows adjacent cells to be deilluminated thus preventing from further deilluminating the cells.
        if (vn[i][j] && f)
        {
            r.push_back(1);
            vn[i][j]--;
            return;
        }
        else
        {
            r.push_back(0);
            return;
        }
        help(vn, r, l, i, j + 1, n, f - 1);
        help(vn, r, l, i + 1, j, n, f - 1);
        help(vn, r, l, i - 1, j - 1, n, f - 1);
        help(vn, r, l, i - 1, j, n, f - 1);
        help(vn, r, l, i - 1, j + 1, n, f - 1);
        help(vn, r, l, i + 1, j + 1, n, f - 1);
        help(vn, r, l, i + 1, j - 1, n, f - 1);
        help(vn, r, l, i, j - 1, n, f - 1);
    }
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        if (!queries.size() || n == 0 || !lamps.size())
            return {};
        vector<vector<int>> vn(n, vector<int>(n, 0));
        vector<int> res;
        for (auto it : lamps)
        {
            ill(it[0], it[1], vn);
        }
        for (auto it : queries)
            help(vn, res, lamps, it[0], it[1], n, 2);
        return res;
    }
};