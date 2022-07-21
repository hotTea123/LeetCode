#include<bits/stdc++.h>
using namespace std;

//改进后的方法一
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

    bool checkTree(TreeNode* node){
        if(node == nullptr)
            return true;
        bool flag = true;
        if(checkTree(node->left))
            node->left = nullptr;
        else
            flag = false;
        if(checkTree(node->right))
            node->right = nullptr;
        else
            flag = false;
        flag &= !node->val;
        return flag;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool flag = checkTree(root);
        if(!flag)
            return root;
        delete root;
        return nullptr;
    }
};