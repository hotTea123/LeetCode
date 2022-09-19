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

class Codec {
private:
    void preOrder(TreeNode* node, string& s){
        if(node == nullptr){
            s += '*';
            return;
        }
        s += '#'+to_string(node->val);
        preOrder(node->left, s);
        preOrder(node->right, s);
    }
    void midOrder(TreeNode* node, string& s){
        if(node == nullptr){
            s += '*';
            return;
        }
        midOrder(node->left, s);
        s += '#'+to_string(node->val);
        midOrder(node->right, s);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        preOrder(root, s);
        s += '/';
        midOrder(root, s);
        cout << s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));