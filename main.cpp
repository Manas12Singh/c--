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
    void reorderList(ListNode *head)
    {
        if (head->next == nullptr || head->next->next == nullptr)
            return;
        ListNode *p1 = head, *p2 = head;
        while (p2->next != nullptr && p2->next->next != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = nullptr;
        while (p1->next != nullptr)
        {
            ListNode *temp = p1->next;
            p1->next = p1->next->next;
            temp->next = p2;
            p2 = temp;
        }
        p1 = head;
        while (p2 != nullptr)
        {
            ListNode *temp = p2;
            p2 = p2->next;
            temp->next = p1->next;
            p1->next = temp;
            p1 = p1->next->next;
        }
    }
};