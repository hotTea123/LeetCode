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
    int m = 0;
    void findLevel(TreeNode* node, int level){
        if(node == nullptr)
            return;
        m = max(m, level);
        findLevel(node->left, level+1);
        findLevel(node->right, level+1);
    }

    void preVisit(TreeNode* node, vector<vector<string>>& res, int level, int low, int high){
        if(node == nullptr)
            return;
        int mid = (low+high)/2;
        res[level][mid] = to_string(node->val);
        preVisit(node->left, res, level+1,low, mid-1);
        preVisit(node->right, res, level+1, mid+1, high);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        findLevel(root, 1);
        int n = pow(2, m) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        preVisit(root, res, 0, 0, n-1);
        return res;
    }
};