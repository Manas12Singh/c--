#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val, height;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode *node)
{
    return node ? node->height : 0;
}

int getBalance(TreeNode *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

void updateHeight(TreeNode *node)
{
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

TreeNode *rr(TreeNode *y)
{
    TreeNode *x = y->right;
    TreeNode *T2 = x->left;
    x->left = y;
    y->right = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

TreeNode *ll(TreeNode *y)
{
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
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

TreeNode *balance(TreeNode *node)
{
    updateHeight(node);
    int bf = getBalance(node);
    if (bf > 1)
    {
        if (getBalance(node->left) < 0)
            node->left = rr(node->left);
        return ll(node);
    }
    if (bf < -1)
    {
        if (getBalance(node->right) > 0)
            node->right = ll(node->right);
        return rr(node);
    }
    return node;
}

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else
        return root;
    return balance(root);
}

void printBT(const string &prefix, const TreeNode *node, bool isLeft, bool hasRight)
{
    if (node != nullptr)
    {
        cout << prefix;

        cout << ((isLeft && hasRight) ? "|-- " : "\\-- ");

        cout << node->val << endl;

        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true, node->right != nullptr);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false, false);
    }
}

int main()
{
    TreeNode *root = nullptr;
    vector<int> nums = {1, 20, 2, 19, 3, 18, 4, 17, 5, 16, 6, 15, 7, 14, 8, 13, 9, 12, 10, 11};
    for (auto i : nums)
        root = insert(root, i);
    printBT("", root, false, false);
    return 0;
}
