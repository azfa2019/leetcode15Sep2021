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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode();
        dummy->next=head;
        auto p=dummy;
        while(p && p->next){
            auto q=p->next->next;
            while(q && q->val==p->next->val) q=q->next;
            if(p->next->next==q) p=p->next;
            else p->next=q;
        }
        return dummy->next;
    }
};
