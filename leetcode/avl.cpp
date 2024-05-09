#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val, count;
    TreeNode *left, *right;
    TreeNode() : val(0), count(1), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), count(1), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), count(1), left(left), right(right) {}
};

TreeNode *rr(TreeNode *root)
{
    TreeNode *temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    return temp;
}

TreeNode *ll(TreeNode *root)
{
    TreeNode *temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    return temp;
}

TreeNode *lr(TreeNode *root)
{
    root->left = rr(root->left);
    return ll(root);
}

TreeNode *rl(TreeNode *root)
{
    root->right = ll(root->right);
    return rr(root);
}

int findHeight(TreeNode *root, int &k)
{
    k = 1;
    if (root == nullptr)
        return 0;
    int lh = findHeight(root->left, k);
    int rh = findHeight(root->right, k);
    if (lh > rh)
    {
        k = -1;
        return lh + 1;
    }
    return rh + 1;
}

int findHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

TreeNode *balance(TreeNode *root)
{
    if (root != nullptr)
    {
        int k1, k2;
        int lh = findHeight(root->left, k1);
        int rh = findHeight(root->right, k2);
        if (lh - rh > 1)
        {
            if (k1 == -1)
                root = ll(root);
            else
                root = lr(root);
        }
        else if (rh - lh > 1)
        {
            if (k2 == 1)
                root = rr(root);
            else
                root = rl(root);
        }
    }
    return root;
}

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);
    if (root->val == val)
        root->count++;
    else if (root->val < val)
        root->right = insert(root->right, val);
    else
        root->left = insert(root->left, val);
    return balance(root);
}

void printTree(TreeNode *root)
{
    int h = findHeight(root), i = 0;
    queue<TreeNode *> q[2];
    q[0].push(root);
    while ((!q[0].empty() || !q[1].empty()) && i < h)
    {
        TreeNode *temp = q[i % 2].front();
        q[i % 2].pop();
        if (temp == nullptr)
        {
            cout << "null"
                 << " ";
            q[(i + 1) % 2].push(nullptr);
            q[(i + 1) % 2].push(nullptr);
        }
        else
        {
            q[(i + 1) % 2].push(temp->left);
            q[(i + 1) % 2].push(temp->right);
            cout << temp->val << " ";
        }
        if (q[i % 2].empty())
            i++;
    }
    cout << endl;
}

int main()
{
    TreeNode *root = nullptr;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : nums)
        root = insert(root, i);
    printTree(root);
    return 0;
}
