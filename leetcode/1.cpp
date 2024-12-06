#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

/* class Node
{
public:
    int count;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        count = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        count = _val;
        children = _children;
    }
}; */

/* class Node
{
public:
    int count;
    vector<Node *> neighbors;
    Node()
    {
        count = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        count = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        count = _val;
        neighbors = _neighbors;
    }
}; */

/* class Node
{
public:
    int count;
    Node *left;
    Node *right;
    Node *next;

    Node() : count(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : count(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : count(_val), left(_left), right(_right), next(_next) {}
}; */

class TrieNode
{
public:
    bool isLast;
    vector<TrieNode *> next;

    TrieNode()
    {
        isLast = false;
        next.assign(26, nullptr);
    }
};

#define PII pair<int, int>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/* struct ListNode
{
    int key;
    int val;
    ListNode *next;

    ListNode() : key(0), val(0), next(nullptr) {}

    ListNode(int x, int y) : key(x), val(y), next(nullptr) {}
    ListNode(int x, int y, ListNode *next) : key(x), val(y), next(next) {}
}; */

class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (auto guard : guards)
            res[guard[0]][guard[1]] = 1;
        for (auto wall : walls)
            res[wall[0]][wall[1]] = -1;
        for (int i = 0; i < m; i++)
        {
            int t = 0;
            for (int j = 0; j < n; j++)
            {
                if (res[i][j] == -1)
                {
                    res[i][j] = t;
                    t = 0;
                }
                if (res[i][j] == 1)
                    t = 1;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
    int target = 9;
    cout << s.largestNumber(cost, target) << endl;
    return 0;
}