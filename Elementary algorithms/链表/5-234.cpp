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
    1.将链表中的数放到数组中判断，需要额外的O(n)时间复杂度
    2.遍历3次链表，第一次获取链表长度，第二次反转链表后半部分，第三次判断链表前半部分和后半部分是否相同
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> A;
        ListNode* p = head;
        while(p != nullptr){
            A.emplace_back(p->val);
            p = p->next;
        }
        int i=0, j=A.size()-1;
        while(i < j){
            if(A[i] != A[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
};