struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* p = list3;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val <= list2->val){
                p->next = list1;
                list1 = list1->next;
            }else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if(list1!=nullptr)
            p->next = list1;
        if(list2!=nullptr)
            p->next = list2;
        return list3->next;
    }
};