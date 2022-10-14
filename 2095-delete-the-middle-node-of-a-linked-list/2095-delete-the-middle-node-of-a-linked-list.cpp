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
    ListNode* deleteMiddle(ListNode* head) {
        auto pre=new ListNode();
        pre->next=head;
        auto fast=pre,slow=pre;
        while(fast->next && fast->next->next) fast=fast->next->next,slow=slow->next;
        
        slow->next=slow->next->next;
        return pre->next;
    }
};