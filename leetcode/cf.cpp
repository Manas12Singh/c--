#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low, int curr, int parent, vector<bool> &isap, int &time)
{
    visited[curr] = true;
    tin[curr] = low[curr] = ++time;
    int c = 0;
    for (int next : adj[curr])
    {
        if (!visited[next])
        {
            c++;
            dfs(adj, visited, tin, low, next, curr, isap, time);
            low[curr] = min(low[curr], low[next]);
            if (parent != -1 && low[next] >= tin[curr])
                isap[curr] = true;
        }
        else if (next != parent)
            low[curr] = min(low[curr], tin[next]);
    }
    if (parent == -1 && c > 1)
        isap[curr] = 1;
    cout << tin[curr] << " " << low[curr] << " " << curr << " " << parent << " " << isap[curr] << " " << time << endl;
}

void findap(vector<vector<int>> &a, int n)
{
    vector<int> tin(n, -1), low(n, -1);
    vector<bool> visited(n, false), isap(n, false);
    int time = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(a, visited, tin, low, i, -1, isap, time);
    for (int i = 0; i < n; i++)
        if (isap[i])
            cout << i << endl;
}

int main()
{
    vector<vector<int>> adj = {{}, {2, 4}, {1}, {4}, {1, 3, 5}, {4, 6}, {5, 7}, {6}};
    findap(adj, 7);
    return 0;
}