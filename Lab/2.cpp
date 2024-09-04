#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int flag = 0;
pair<int, int> p = {0, 0};
void cycle(vector<vector<int>> g, vector<bool> &v, int curr, int par, int count)
{
    if (v[curr] == true)
        p.first = 1, p.second = max(p.second, count);
    v[curr] = true;
    cout << count << " ";
    for (int i = 0; i < g[curr].size(); i++)
    {
        if (!v[g[curr][i]])
            cycle(g, v, g[curr][i], curr, count + 1);
        else if (g[curr][i] != par)

    }
}
void bi(vector<vector<int>> g)
{
    vector<bool> v(g.size(), false);
    for (int i = 0; i < g.size(); i++)
    {
        if (!v[i])
        {
            auto it = cycle(g, v, i, -1, 1);
            if (!it.first)
            {
                cout << "bipartite";
                exit(0);
            }
            else
            {
                if (it.second % 2 == 0)
                {
                    cout << "bipartite";
                    exit(0);
                }
                else
                {
                    cout << "not bipartite";
                    exit(0);
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> g = {
        {1, 3}, // Node 0 is connected to nodes 1 and 3
        {0, 2}, // Node 1 is connected to nodes 0 and 2
        {1, 3}, // Node 2 is connected to nodes 1 and 3
        {0, 2}};
    bi(g);
    return 0;
}