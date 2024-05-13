#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

struct TreeNode {
    int count;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : count(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : count(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : count(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid) {
        int m = grid.size();
        vector<vector<int>> res(m-2, vector<int>(n-2));

    }
};

int main() {
    Solution s;
    return 0;
}