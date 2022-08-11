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

/*
    使用一个全局变量pos指示preorder遍历到的地方，通过preorder不停的将inorder划分为节点/左子树/右子树,
  中间需要在inorder中遍历low~high找到值为preorder[pos]的那个点(也就是根节点),故整个时间复杂度为O(n²)
  这块可以通过map反向存储<值，索引>而在O(1)时间复杂度查到，见105_2
*/
class Solution {
private:
    int pos;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int low, int high){
        TreeNode* p = new TreeNode(preorder[pos]);
        if(low == high)
            return p;
        int i;
        for(i=low;i <= high;i++){
            if(inorder[i] == preorder[pos])
                break;
        }
        if(i != low){
            ++pos;
            p->left = build(preorder, inorder, low, i-1);
        }
        if(i != high){
            ++pos;
            p->right = build(preorder, inorder, i+1, high);
        }
        return p;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pos = 0;
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};
