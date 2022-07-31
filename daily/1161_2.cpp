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

struct Tree{
    TreeNode* createTree(vector<string>& data){
        int pos = 0;
        return createNode(data, pos);
    }

    TreeNode* createNode(vector<string>& data, int pos){
        if(pos >= data.size() || data[pos] == "null")
            return nullptr;

        //在data中left、right的pos
        int left_pos = 2 *(pos+1) - 1;
        int right_pos = left_pos + 1;
        int val = atoi(data[pos].c_str());
        return new TreeNode(val, createNode(data, left_pos), createNode(data, right_pos));
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int res = 1, maxSum = root->val, level=0;
        while(!qu.empty()){
            int sum = 0, n=qu.size();
            ++level;
            //遍历某一层
            for(int i=0;i < n;i++){
                TreeNode* q = qu.front();
                qu.pop();
                sum += q->val;
                if(q->left != nullptr)
                    qu.push(q->left);
                if(q->right != nullptr)
                    qu.push(q->right);
            }
            if(sum > maxSum){
                maxSum = sum;
                res = level;
            }
        }
        return res;
    }
};

int main(){
    Tree tree;
    vector<string> data = {"1","3","2"};
    TreeNode* root = tree.createTree(data);
    int res = Solution().maxLevelSum(root);
    return 0;
}