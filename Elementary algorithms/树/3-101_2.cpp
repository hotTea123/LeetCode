#include<bits/stdc++.h>
using namespace std;

//双指针
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution {
private:
    bool check(TreeNode* p, TreeNode* q){
        if(p==nullptr && q==nullptr)
            return true;
        if(p==nullptr || q==nullptr || p->val!=q->val)
            return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};