#include<algorithm>
using namespace std;


class Solution {
private:
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0), left(nullptr), right(nullptr){}
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
        TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
    };


public:
    int maxDepth(TreeNode* root) {
        int levelL = 0, levelR = 0;
        if(root->left != nullptr)
            levelL =  maxDepth(root->left);
        if(root->right != nullptr)
            levelR = maxDepth(root->left);
        return max(levelL, levelR) + 1;
    }
};