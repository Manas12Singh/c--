#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void addOneToList(ListNode *node, int &carry)
{
    if (node == nullptr)
    {
        carry = 1;
        return;
    }
    addOneToList(node->next, carry);
    if (carry)
    {
        node->val++;
        carry = node->val / 10;
        node->val %= 10;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ListNode *head = nullptr, *trav = nullptr;
        for (int i = 0; i < n; i++)
        {
            if (head == nullptr)
                trav = head = new ListNode();
            else
            {
                trav->next = new ListNode();
                trav = trav->next;
            }
            cin >> trav->val;
        }
        printList(head);
        int carry = 0;
        addOneToList(head, carry);
        if (carry)
            head = new ListNode(1, head);
        printList(head);
    }
    return 0;
}