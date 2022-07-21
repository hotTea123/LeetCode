#include<map>
#include<vector>
#include<queue>
using namespace std;

/* **********
 * 解法一：层次遍历，使用一个pair将节点和层数绑定
 * 时间复杂度O(n), 空间复杂度O(logn)
 * **********/

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
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<pair<TreeNode*, int>> que;
        map<int, int> res;
        vector<int> out;
        int level = 0;
        que.emplace(root, level);
        while(!que.empty()){
            pair<TreeNode*, int> nodeInfo = que.front();
            TreeNode* node = nodeInfo.first;
            level = nodeInfo.second;
            //auto [node, level] = nodeInfo;
            que.pop();
            if(res.find(level) == res.end() || node->val > res[level])
                res[level] = node->val;
            if(node->left != nullptr)
                que.emplace(node->right, level+1);
            if(node->right != nullptr)
                que.emplace(node->right, level+1);            
        }

        out.reserve(res.size());
        for(auto& n: res)
            out.emplace_back(n.second);
        return out; 
    }
};