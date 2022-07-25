#include<bits/stdc++.h>
using namespace std;

/*
    我们知道，在完全二叉树中，如果从1开始层次编号所有节点，节点号为i的节点的左孩子节点为2i，右孩子节点
  为2i+1，因此我们只需要统计二叉树中节点个数，插入的时候算出插入的节点的编号，判断%2是1还是0，为0则表
  示该节点是它父节点的左孩子，为1则是它父节点的右孩子，把这些信息存下来(我是放到一个数组里)，一直%2则
  会得到一条左/右孩子的选择路径直到为1则表示到达根节点了，倒叙遍历该数组即可得到从根节点出发到要插入节
  点位置的所有的左右孩子选择方式。
    初始化时需要遍历一遍树计算出当前的节点数目，时间复杂度为O(n),每次插入时间复杂度为O(logn)
*/
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

class Tree{
public:
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
};

class CBTInserter {
private:
    TreeNode* root;
    int cnt;

    void visit(TreeNode* node){
        if(node == nullptr)
            return;
        visit(node->left);
        visit(node->right);
        ++cnt;
    }

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        cnt = 0;
        visit(root);
    }
    
    int insert(int val) {
        ++cnt;
        vector<bool> lr;   //true为左，false为右
        int n = cnt;
        while(n > 1){
            if(n & 1)
                lr.emplace_back(false);
            else
                lr.emplace_back(true);
            n >> 1;
        }
        TreeNode* node = root;
        for(int i = lr.size()-1; i > 0;i--)
            node = lr[i] ? node->left:node->right;

        if(lr[0])
            node->left = new TreeNode(val);
        else
            node->right = new TreeNode(val);

        return node->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};


int main(){
    Tree tree;
    vector<int> data = {1,2};
    TreeNode* root = tree.createTree(data);
    CBTInserter cbt(root);
    return 0;
}