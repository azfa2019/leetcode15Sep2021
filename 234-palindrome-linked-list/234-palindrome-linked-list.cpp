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
    bool isPalindrome(ListNode* head) {
        if(!head||!(head->next)) return true;
        auto fast=head,slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        auto right=reverse(slow);
        while(right){
            if(right->val!=head->val) return false;
            right=right->next;
            head=head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre=nullptr;
        while(head){
            auto tmp=head->next;
            head->next=pre;
            pre=head;
            head=tmp;
        }
        return pre;
    }
};