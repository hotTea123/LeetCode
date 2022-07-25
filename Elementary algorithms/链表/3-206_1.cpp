#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* H = new ListNode(0, head);
        ListNode* tail = head;
        ListNode* p = tail->next;
        while(p != nullptr){
            tail->next = p->next;
            p->next = H->next;
            H->next = p;
            p = tail->next;
        }
        return H->next;
    }
};