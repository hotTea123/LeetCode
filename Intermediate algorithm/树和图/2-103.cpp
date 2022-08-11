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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> st;
        st.push(root);
        bool flag = true;    //为true表示从左往右
        vector<int> temp;
        while(!st.empty()){
            int n = st.size();
            for(int i=0;i < n;i++){
                TreeNode* node = st.front();
                st.pop();
                if(node == nullptr)
                    continue;
                temp.emplace_back(node->val);
                st.push(node->left);
                st.push(node->right);
                
            }
            if(!flag)
                reverse(temp.begin(), temp.end());
            if(temp.size())
                res.emplace_back(temp);
            temp.clear();
            flag = !flag;
        }
        return res;
    }
};