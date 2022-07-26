#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 //头插法，很经典的方法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* H = new ListNode(), *p = head;
        while(p != nullptr){
            ListNode* q = p->next;
            p->next = H->next;
            H->next = p;
            p = q;
        }
        return H->next;
    }
};