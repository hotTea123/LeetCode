#include <bits/stdc++.h>
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

//2022.8.30 每日一题  循环
class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        TreeNode *p = new TreeNode(val);
        if (val > root->val)
        {
            p->left = root;
            return p;
        }
        TreeNode *node = root;
        while (1)
        {
            if (node->right == nullptr)
            {
                node->right = p;
                break;
            }
            if (val > node->right->val)
            {
                p->left = node->right;
                node->right = p;
                break;
            }
            node = node->right;
        }
        return root;
    }
};