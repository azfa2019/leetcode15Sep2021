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
    void reorderList(ListNode* head) {
        auto mid=midnode(head);
        auto head2=reverse(mid);
        while(head2->next){
            auto ne=head->next;
            auto ne2=head2->next;
            head->next=head2;
            head2->next=ne;
            head=ne;
            head2=ne2;
        }
    }
    ListNode *midnode(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(head && head->next){
            slow=slow->next;
            head=head->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode* head){
        ListNode *pre=NULL,*cur=head;
        while(cur){
            auto ne=cur->next;
            cur->next=pre;
            pre=cur;
            cur=ne;
        }
        return pre;
    }
};