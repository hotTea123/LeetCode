#include<bits/stdc++.h>
using namespace std;

/*
    企图通过两个序列是否一样来获取答案，这两个序列一个是遍历左根右，另一个是遍历右根左
    但是直接这样做会有bug，比如对于[2,2,null]和[2,null,2]不管怎么遍历都无法区分，因此我又加入了一个‘*’
  用来表示null的地方，结果还是有bug，那就是有的树他们左根右和右根左是一样的，就连null的位置都一样，但是他
  们却不对称，于是我只能再加入一些别的信息到序列中(比如层数)，最后是通过了
    但是换个思路，为什么一定要通过比较某种遍历的结果来得到答案呢？题目判断对称为什么不直接按照是否对称做递
  归呢？我也想过这样直接做，但我发现这样求出来的是每个节点都是镜像对称的一棵树，于是我放弃了这种做法，但是
  稍微改变一下思路，使用两颗指针分别指向根节点的左子树p和右子树q，整体轴对称代表着只需要判断p的左子树是否
  等于q的右子树以及p的右子树是否等于q的左子树，一直这样递归下去。本质上也就是一个双指针的题，可是我没有想
  到。
*/
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
    void Previsit(TreeNode* node, string& s1, int level){
        if(node==nullptr)
            return;
        Previsit(node->left, s1, level+1);
        s1 += to_string(level)+to_string(node->val);
        Previsit(node->right, s1, level+1);
    }
    void Postvisit(TreeNode* node, string& s2, int level){
        if(node == nullptr)
            return;
        Postvisit(node->right, s2,level+1);
        s2+=to_string(level)+to_string(node->val);
        Postvisit(node->left, s2,level+1);
    }
public:
    bool isSymmetric(TreeNode* root) {
        string s1="", s2="";
        int level = 0;
        Previsit(root, s1, level);
        Postvisit(root, s2, level);
        if(s1==s2)
            return true;
        return false;
    }
};