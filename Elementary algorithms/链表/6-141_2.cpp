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
        ListNode *p = head, *q = head;
        while(p != nullptr && p->next!=nullptr){
            p = p->next->next;
            q = q->next;
            if(p == q)
                return true;
        }
        return false;
    }
};