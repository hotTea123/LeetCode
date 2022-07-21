#include<bits/stdc++.h>
using namespace std;

/*  官方题解的思路，注意之间的差别，就跟我写createTree一样，我老是喜欢去判断左右孩子是否为空，然后分别判断，
   但其实根本不需要，就算是空也可以递归进去，然后判空退出来就是了；
*/
class Solution {
private:
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr){}
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
    };

    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left==nullptr && root->right==nullptr && !root->val)
            return nullptr;
        return root;
    }
};