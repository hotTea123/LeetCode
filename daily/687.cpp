#include <bits/stdc++.h>
using namespace std;

// 2022.9.2 每日一题
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree
{
public:
    // data = [1,3,2,5,3,null,9]
    TreeNode *createTree(vector<string> &data)
    {
        int pos = 0;
        return createNode(data, pos);
    }

    TreeNode *createNode(vector<string> &data, int pos)
    {
        if (pos >= data.size() || data[pos] == "null")
            return nullptr;

        //在data中left、right的pos
        int left_pos = 2 * (pos + 1) - 1;
        int right_pos = left_pos + 1;
        int val = atoi(data[pos].c_str());
        return new TreeNode(val, createNode(data, left_pos), createNode(data, right_pos));
    }
};

class Solution {
private:
    int res = 0;
    // len- val
    int findPathlen(TreeNode* node){
        if(node == nullptr)
            return 0;
        int maxlen=0;
        bool flagl = 0, flagr = 0;
        if(node->left != nullptr && node->val == node->left->val)
            flagl = 1;
        if(node->right != nullptr && node->val == node->right->val)
            flagr = 1;
        int l1 = findPathlen(node->left);
        int l2 = findPathlen(node->right);
        if(flagl){
            ++l1;
            maxlen = max(maxlen, l1);
        }
        if(flagr){
            ++l2;
            maxlen = max(maxlen, l2);
        }
        res = max(res, maxlen);
        if(flagr && flagl)
            res = max(res, l1+l2);
        return maxlen;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        findPathlen(root);
        return res;
    }
};

int main()
{
    Tree tree;
    vector<string> data = {"5","4","5","4","4","5","3","4","4","null","null","null","4","null","null","4","null","null","4","null","4","4","null","null","4","4"};
    TreeNode *root = tree.createTree(data);
    int res = Solution().longestUnivaluePath(root);
    return 0;
}