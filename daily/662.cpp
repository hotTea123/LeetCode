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

//2022.8.27 每日一题
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long res=1;
        queue<pair<TreeNode*,long long>> que;
        que.push(make_pair(root, 1));
        while(!que.empty()){
            int n = que.size();
            long long start = 0;
            for(int i=0;i < n;i++){
                auto [node, idx] = que.front();
                que.pop();
                if(start == 0)
                    start = idx-1;
                idx -= start;
                if(node->left != nullptr)
                    que.push(make_pair(node->left, 2*idx));
                if(node->right != nullptr)
                    que.push(make_pair(node->right, 2*idx+1));
                res = max(res, idx);
            }
        }
        return res;
    }
};