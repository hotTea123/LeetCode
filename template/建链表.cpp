#include<bits/stdc++.h>
using namespace std;

class List{
public:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

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

int main(){
    List list;
    vector<int> data = {4,5,1,9};
    List::ListNode* node = list.createList(data);
    return 0;
}