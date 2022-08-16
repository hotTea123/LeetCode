#include<bits/stdc++.h>
using namespace std;

// 2022.8.17  每日一题
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int preSum = 0;
        while(!que.empty()){
            int n=que.size(), sum = 0;
            for(int i=0;i < n;i++){
                TreeNode* node =  que.front();
                que.pop();
                if(node == nullptr)
                    continue;
                que.push(node->left);
                que.push(node->right);
                sum += node->val;
            }
            if(sum != 0)
                preSum = sum;
        }
        return preSum;
    }
};