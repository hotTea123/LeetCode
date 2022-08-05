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
    一定要在每次for循环开始前固定n = que.size()而不是写在for循环里面，因为que.size()在运行时候
  会不停改变
*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, nullptr);
        queue<TreeNode*> que;
        int level = 0;
        que.push(root);
        while(!que.empty()){
            ++level;
            int n = que.size();
            for(int i=0;i < n;i++){
            //这里切勿写成for(int i=0;i < que.size();i++)
                TreeNode* node = que.front();
                que.pop();
                if(node == nullptr)
                    continue;
                if(level == depth-1){
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }else{
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};