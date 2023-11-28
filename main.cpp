#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> a;
        vector<vector<int>> res;
        for (auto &&i : items1)
            a[i[0]] = i[1];
        for (auto &&i : items2)
            a[i[0]] += i[1];
        for (auto &&i : a)
            res.push_back(vector<int>{i.first, i.second});
        return res;
    }
};

int main()
{
    for (int i = 1; i < 10000000; i *= 3)
        cout << (bitset<16>)i << endl;
}
