#include<algorithm>
#include<map>
using namespace std;

//不额外用map存储
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
    int preVal;
    bool first = true;
    
public:
    bool isValidBST(TreeNode* node){
        if(node->left != nullptr)
            if(!isValidBST(node->left))
                return false;
        if(first){
            preVal = node->val;
            first = false;
        }else{
            if(node->val <= preVal)
                return false;
            preVal = node->val;
        }
        
        if(node->right != nullptr)
            if(!isValidBST(node->right))
                return false;
        return true;
    }
};
