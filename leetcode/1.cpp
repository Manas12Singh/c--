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
    int res;
    int helper(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        if (root->left == nullptr)
        {
            if (r == 0)
            {
                res++;
                return 2;
            }
            else
                r - 1;
        }
        if (root->right == nullptr)
        {
            if (l == 0)
            {
                res++;
                return 2;
            }
            else
                return l - 1;
        }
        if (min(l, r) == 0)
        {
            res++;
            return 2;
        }
        return max(l, r) - 1;
    }

public:
    int minCameraCover(TreeNode *root)
    {
        res = 0;
        if (helper(root) == 0)
            res++;
        return res;
    }
};

int main()
{
    Solution s();
    return 0;
}