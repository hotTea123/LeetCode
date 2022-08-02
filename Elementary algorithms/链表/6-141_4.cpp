#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *p = head;
        ListNode *H = new ListNode(0);
        while(p != NULL){
            ListNode *q = p->next;
            p->next = H->next;
            H->next = p;
            p = q;
        }
        if(H->next == head)
            return true;
        return false;
    }
};