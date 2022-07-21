#include<map>
#include<vector>
#include<queue>
using namespace std;

/* **********
 * 解法一：深度优先遍历，递归的遍历并判断level
 * 时间复杂度O(n), 空间复杂度O(logn)
 * **********/

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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        int initLevel = 0;
        vector<int> res;
        maxVal(root, initLevel, res);
    }

    void maxVal(TreeNode* node, int level, vector<int>& res){
        if(level > res.size()){
            res.emplace_back(node->val);
        }else if(node->val > res[level]){
            res[level] = node->val;
        }
        if(node->left != nullptr)
            maxVal(node->left, level+1, res);
        if(node->right != nullptr)
            maxVal(node->right, level+1, res);
    }
};