#include<bits/stdc++.h>
using namespace std;

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
    int pos;
    unordered_map<int, int> hash;
    TreeNode* build(vector<int>& preorder, int low, int high){
        TreeNode* p = new TreeNode(preorder[pos]);
        if(low == high)
            return p;
        int i = hash[preorder[pos]];
        if(i != low){
            ++pos;
            p->left = build(preorder, low, i-1);
        }
        if(i != high){
            ++pos;
            p->right = build(preorder, i+1, high);
        }
        return p;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos = 0;
        for(int i=0;i < inorder.size();i++)
            hash[inorder[i]] = i;
        return build(preorder, 0, inorder.size()-1);
    }
};

