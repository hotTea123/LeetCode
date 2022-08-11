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
    使用两个指针分别循环遍历两个链表，最终他们会同时要么指向一个节点，要么都指向空指针
    时间复杂度O(gcd(m,n)*(m+n))
    可以看到该方法的运行时间是方法一的快10倍，但思路很巧妙
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* p = headA, *q = headB;
        while(p != q){
            p = p==nullptr ? headA: p->next;
            q = q==nullptr ? headB: q->next;
        }
        return p;
    }
};