#include <iostream>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
}; */

/* class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
}; */

/* class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
}; */

class Solution {
    void heapify(vector<int> &heap, vector<int> &score, int index, int n) {
        int minIndex = index;
        if (index * 2 + 1 < n && score[heap[minIndex]] > score[heap[index * 2 + 1]])
            minIndex = index * 2 + 1;
        if (index * 2 + 2 < n && score[heap[minIndex]] > score[heap[index * 2 + 2]])
            minIndex = index * 2 + 2;
        if (index != minIndex) {
            swap(heap[index], heap[minIndex]);
            heapify(heap, score, minIndex, n);
        }
    }

    void buildHeap(vector<int> &heap, vector<int> &score) {
        int n = heap.size();
        for (int i = n / 2; i > -1; i--)
            heapify(heap, score, i, n);
    }

public:
    vector<string> findRelativeRanks(vector<int> &score) {
        int n = score.size();
        vector<int> heap(n);
        for (int i = 0; i < n; i++)
            heap[i] = i;
        buildHeap(heap, score);
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            switch (i) {
                case 0:
                    res[heap[0]] = "Gold Medal";
                    break;
                case 1:
                    res[heap[0]] = "Silver Medal";
                    break;
                case 2:
                    res[heap[0]] = "Bronze Medal";
                    break;
                default:
                    res[heap[0]] = to_string(i + 1);
            }
            swap(heap[0], heap[n - i - 1]);
            heapify(heap, score, 0, n - i - 2);
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}