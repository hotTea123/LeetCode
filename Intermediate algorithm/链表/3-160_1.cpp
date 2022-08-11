#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    统计两个链表的长度l1,l2，将长的链表往后移|l1-l2|,用两指针指向两个链表，判断他们是否会相等
    时间复杂度O(m+n)
*/
class Solution {
private:
    int len(ListNode* head){
        ListNode* p =head;
        int ret = 0;
        while(p != nullptr){
            ++ret;
            p = p->next;
        }
        return ret;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA), lenB = len(headB);
        ListNode* p = lenA > lenB ? headA : headB;
        ListNode* q = lenA <= lenB ? headA : headB;
        int n = abs(lenA-lenB);
        while(n > 0){
            p = p->next;
            --n;
        }
        while(p!= nullptr && q!= nullptr){
            if(p == q)
                return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};