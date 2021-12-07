/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=new ListNode(0,head);
        ListNode* slow=pre, *fast=pre;
        for(int i=0;i<n;i++) fast=fast->next;
        while(fast->next!=nullptr ) {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return pre->next;
    }
};
// _  1
// ds p
//  _ 1 2 3 4 5
//  p   p      
//        p   p    