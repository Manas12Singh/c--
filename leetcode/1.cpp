#include <bits/stdc++.h>

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

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define isqrt(x) floor(sqrt(x))
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class TrieNode
{
public:
    bool isLast;
    vector<TrieNode *> next;
    int count;

    TrieNode(int n)
    {
        isLast = false;
        next.assign(n, nullptr);
        count = 0;
    }
};

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<long> dist(n, LONG_MAX);
        dist[0] = 0;
        vector<long> cnt(n, 0);
        cnt[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (auto &road : roads)
            {
                int a = road[0];
                int b = road[1];
                long c = road[2];
                if (dist[a] > dist[b])
                    swap(a, b);
                if (dist[a] != LONG_MAX)
                {
                    if (dist[a] + c < dist[b])
                    {
                        dist[b] = (dist[a] + c) % (long)10e12;
                        cnt[b] = 0;
                    }
                    cnt[b] = (cnt[b] + cnt[a]) % (int)(10e9 + 7);
                }
            }
        }
        return cnt[n - 1];
    }
};
int main()
{
    Solution S;
    return 0;
}