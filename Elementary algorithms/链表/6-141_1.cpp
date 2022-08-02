#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    4种方法，分别对应_1,_2,_3,_4
    1.遍历链表，将遍历过的链表放入set判断是否有重复的
    2.使用快慢指针，如果有环快慢指针一定会相遇
    3.遍历链表，将遍历过的节点指向自己，如果后面遍历到有指向自己的节点说明有环
    4.反转链表(直接用头插法)，如果有环反转前后的头节点会一样
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> addr;
        ListNode *p = head;
        while(p!=nullptr){
            if(addr.find(p) != addr.end())
                return true;
            addr.insert(p);
            p = p->next;
        }
        return false;
    }
};