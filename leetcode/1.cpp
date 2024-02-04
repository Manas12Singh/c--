#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <stdint.h>
#include <map>
#include <set>
#include <random>
#include <string>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node
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
};

class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0, j = 0, l = -1, r = -1;
        int n = 0;
        map<char, int> m;

        for (auto &ch : t) {
            if (m[ch] == 0) {
                n++;
                m[ch] = 1;
            } else {
                m[ch]++;
            }
        }

        while (i < s.size() && j < s.size()) {
            if (n == 0) {
                if (l == -1 || (r - l > j - i)) {
                    r = j;
                    l = i;
                }
                if (m[s[i]] != 0) {
                    if (m[s[i]] == 0) {
                        n++;
                    }
                    m[s[i]]++;
                }
                i++;
            } else {
                if (m[s[j]] != 0) {
                    m[s[j]]--;
                    if (m[s[j]] == 0) {
                        n--;
                    }
                }
                j++;
            }
        }

        if (l == -1) {
            return "";
        }
        return s.substr(l, r - l + 1);
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << solution.minWindow(s, t) << endl;

    return 0;
}
