#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };


class List{
public:
    ListNode* createList(vector<int>& data){
        return createNode(data, 0);
    }

    ListNode* createNode(vector<int>& data, int pos){
        ListNode* node = new ListNode(data[pos]);
        ++pos;
        if(pos < data.size())
            node->next = createNode(data, pos);
        return node;
    }
};


class Solution {
public:
    //解法1
    void deleteNode1(ListNode* node) {
        ListNode* parent;
        while(node->next != NULL){
            node->val = node->next->val;
            parent = node;
            node = node->next;
        }
        delete node;
        parent->next = NULL;
    }

    //解法2
    void deleteNode2(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }

};

int main(){
    vector<int> data = {4,5,1,9};
    ListNode* lst = List().createList(data);
    ListNode* node = lst->next;
    Solution().deleteNode1(node);
    return 0;
}
