#include <bits/stdc++.h>
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
    unordered_map<int, int> m;
    vector<int> parent;
    vector<int> size;
    int findP(int i)
    {
        if (i != parent[i])
            parent[i] = findP(parent[i]);
        return parent[i];
    }
    void Union(int a, int b)
    {
        a = findP(a);
        b = findP(b);
        if (a != b)
        {
            if (size[a] > size[b])
                size[a] += size[b], parent[b] = a;
            else
                size[b] += size[a], parent[a] = b;
        }
    }
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            m[nums[i]] = parent[i] = i;
        for (int &i : nums)
        {
            if (m.find(i + 1) != m.end())
                Union(m[i], m[i + 1]);
            if (m.find(i - 1) != m.end())
                Union(m[i], m[i - 1]);
        }
        int res = 0;
        for (auto &i : size)
            res = max(i, res);
        return res;
    }
};

int main()
{
    Solution s;
    return 0;
}