#include<bits/stdc++.h>
using namespace std;


class Tree{
public:
    struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
    };


    //data = [1,3,2,5,3,null,9]
    TreeNode* createTree(vector<int>& data){
        int pos = 0;
        return createNode(data, pos);
    }

    TreeNode* createNode(vector<int>& data, int pos){
        if(pos >= data.size() || data[pos] == -1)
            return nullptr;

        //在data中left、right的pos
        int left_pos = 2 *(pos+1) - 1;
        int right_pos = left_pos + 1;
        return new TreeNode(data[pos], createNode(data, left_pos), createNode(data, right_pos));
    }

    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        int initLevel = 0;
        vector<int> res;
        maxVal(root, initLevel, res);
        return res;
    }

    void maxVal(TreeNode* node, int level, vector<int>& res){
        if(level >= res.size()){
            res.emplace_back(node->val);
        }else if(node->val > res[level])
            res[level] = node->val;
        if(node->left != nullptr)
            maxVal(node->left, level+1, res);
        if(node->right != nullptr)
            maxVal(node->right, level+1, res);
    }
};


int main(){
    Tree tree;
    vector<int> data = {1,3,2,5,3,-1,9};
    Tree::TreeNode* root = tree.createTree(data);
    vector<int> res = tree.largestValues(root);
    return 0;
}