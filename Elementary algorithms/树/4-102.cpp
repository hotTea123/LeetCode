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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        q.push(make_pair(root, 0));
        int level = 0;
        vector<int> nodes;
        while(!q.empty()){
            auto [p, i] = q.front();
            q.pop();
            if(p == nullptr)
                continue;
            if(level != i){
                ++level;
                res.emplace_back(nodes);
                nodes.clear();
            }
            nodes.emplace_back(p->val);
            q.push(make_pair(p->left, i+1));
            q.push(make_pair(p->right, i+1));
        }
        res.emplace_back(nodes);
        return res;
    }
};