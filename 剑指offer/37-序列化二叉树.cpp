#include <bits/stdc++.h>
using namespace std;

/*
    序列化二叉树的两种方法：
    1.层次遍历
    2.先序遍历，采用x(l)(r)的格式，使用递归下降解码
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        string res = "";
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node == nullptr){
                res += '#';
                continue;
            }
            res += to_string(node->val)+'*';
            que.push(node->left);
            que.push(node->right);
        }
        int pos;
        for(int i=res.size()-1;i >= 0;i--){
            if(res[i] != '#'){
                pos = i;
                break;
            }
        }
        res.resize(pos+1);
        cout << res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string s="";

        bool flag = true;
        for(auto d:data){
            if(d != '*' && d != '#'){
                s += d;
            }else if(d == '*'){
                if(flag){
                    TreeNode* root = new TreeNode(stoi(s));
                    s = "";
                }
            }else{
                
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));