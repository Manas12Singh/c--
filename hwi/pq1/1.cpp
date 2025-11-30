#include <bits/stdc++.h>
#define L long
using namespace std;

vector<L> tree;
vector<L> updateTree;
vector<L> nums;
void buildTree(L start, L end, L i)
{
    if (start == end)
    {
        tree[i] = nums[start];
        return;
    }
    L mid = start + (end - start) / 2;
    buildTree(start, mid, 2 * i + 1);
    buildTree(mid + 1, end, 2 * i + 2);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}

L update(L start, L end, L l, L r, L i)
{
    if (l <= start && end <= r)
    {
        tree[i]=(r-l+1)*()
    }
}

int main()
{
    L n;
    cin >> n;
    nums.resize(n);
    for (L &i : nums)
        cin >> i;
    tree.resize(4 * n, 0);
    updateTree.resize(4 * n, 0);
    buildTree(0, n - 1, 0);
    L q;
    cin >> q;
    for (L i = 0; i < q; i++)
    {
        L q, start, end;
        cin >> q >> start >> end;
        if (q == 1)
        {
            update(0, n - 1, start, end, 0);
        }
    }
}