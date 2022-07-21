#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1, *q=l2;
        int flag = 0;
        while(p!= nullptr && q!= nullptr){
            if(p->val+q->val+flag >= 10){
                p->val += q->val + flag - 10;
                flag = 1;
            }else{
                p->val += q->val + flag;
                flag = 0;
            }
            if(p->next == nullptr && q->next != nullptr){
                p->next = q->next;
                p = p->next;
                break;
            }else if(p->next == nullptr && q->next == nullptr){
                if(flag == 1)
                    p->next = new ListNode(1);
                return l1;
            }
            p = p->next;
            q = q->next;
        }
        while(p != nullptr && flag != 0){
            if(p->val+flag >= 10){
                flag = 1;
                p->val = 0;
            }else{
                p->val += flag;
                flag = 0;
            }
            if(p->next == nullptr)
                break;
            p = p->next;
        }
        if(flag != 0)
            p->next = new ListNode(1);
        return l1;
    }
};