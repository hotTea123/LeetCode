#include<algorithm>
#include<map>
using namespace std;

//中序遍历，把所有遍历过的节点放到一个map，判断map是否是有序的
//注意之前的一种错误写法：没有完全弄清楚二叉搜索树规则，仅仅简单让当前节点大于左边的节点，小于右边的节点
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
    int id;
    map<int, int> nums;
    
public:
    Solution():id(0) {}

    bool isValidBST(TreeNode* root) {
        inOrder(root, nums);
        int pre = nums.begin()->second;
        auto iter = ++nums.begin();
        while(iter != nums.end()){
            if(iter->second <= pre)
                return false;
            pre = iter->second;
            iter++;
        }
        return true;
        
    }


    void inOrder(TreeNode* node, map<int, int>& nums){
        if(node->left != nullptr)
            inOrder(node->left, nums);
        nums[id] = node->val;
        ++id;
        if(node->right != nullptr)
            inOrder(node->right, nums);
    }
};
