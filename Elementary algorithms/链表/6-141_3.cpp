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
        ListNode *p = head;
        while(p != nullptr){
            if(p->next == p)
                return true;
            ListNode *q = p->next;
            p->next = p;
            p = q;
        }
        return false;
    }
};