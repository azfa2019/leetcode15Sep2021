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
        auto dummy=new ListNode();
        dummy->next=head;
        auto fast=dummy,slow=dummy;
        for(int i=1;i<n;i++) fast=fast->next;
        //cout<<fast->val<<endl;
        while(fast->next->next){
            fast=fast->next;
            slow=slow->next;
        }
        //cout<<slow->val<<endl;
        slow->next=slow->next->next;
        return dummy->next;
    }
};