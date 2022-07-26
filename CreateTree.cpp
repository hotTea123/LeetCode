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

int main(){
    Tree tree;
    vector<string> data = {"1","3","2","5","3","null","9"};
    Tree::TreeNode* root = tree.createTree(data);
    return 0;
}