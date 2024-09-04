#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

namespace std
{
    using PairOfPairs = pair<int, pair<int, int>>;
    struct Compare
    {
        bool operator()(PairOfPairs &a, PairOfPairs &b)
        {
            return a.first > b.first;
        }
    };

    vector<vector<int>> prims(vector<vector<pair<int, int>>> a, int start)
    {
        int n = a.size();
        vector<int> parent(n, -1), weight(n, INT_MAX);
        priority_queue<PairOfPairs, vector<PairOfPairs>, Compare> pq;   
    }
}