#include<algorithm>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL)
            return NULL;
        ListNode* H = new ListNode(0);
        H->next = head;
        ListNode* node = H;
        head = H;
        for(int i = 0;i < n;i++)
            node = node->next;
        while(node->next != NULL){
            head = head->next;
            node = node->next;
        }
        if(head->next->next == NULL)
            head->next = NULL;
        else
            head->next = head->next->next;
        return H->next;
    }
};