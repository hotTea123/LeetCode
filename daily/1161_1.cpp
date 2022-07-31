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
    常规使用pair存节点和层数，要注意在最后还要判断一次sum和maxSum因为我是在下一层才去判断上一层的节点
  总和的
*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> qu;
        qu.push(make_pair(root, 1));
        int res = 1, sum = 0, pre = 1, maxSum = INT_MIN;
        while(!qu.empty()){
            auto [node, level] = qu.front();
            qu.pop();
            if(node == nullptr)
                continue;
            qu.push(make_pair(node->left, level+1));
            qu.push(make_pair(node->right, level+1));
            if(level == pre){
                sum += node->val;
            }else{
                if(sum > maxSum){
                    res = pre;
                    maxSum = sum;
                }
                sum = node->val;
                pre = level;
            }
        }
        if(sum > maxSum){
            return pre;
        }
        return res;
    }
};