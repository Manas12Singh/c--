#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};

void zip(ListNode *head, int n)
{
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *trav = head;
    for (int i = 0; i < n / 2; i++)
        trav = trav->next;
    ListNode *nL = nullptr;
    while (trav->next != nullptr)
    {
        ListNode *temp = trav->next;
        trav->next = trav->next->next;
        temp->next = nL;
        nL = temp;
    }
    for (int i = 0; i < n / 2; i++)
    {
        ListNode *temp = nL;
        nL = nL->next;
        temp->next = head->next;
        head->next = temp;
        head = temp->next;
    }
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
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
        zip(head, n);
        printList(head);
    }
    return 0;
}