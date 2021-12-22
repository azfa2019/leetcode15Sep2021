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
        if(!head) return;
        ListNode* fast=head, *slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        auto right=reverse(slow);
        auto left=head;
        while(left && right){
            ListNode* tmp=left->next;
            left->next=right;
            left=tmp;
            tmp=right->next;
            right->next=left;
            right=tmp;
        }
        if(left) left->next=nullptr;
    }
    //.   lt
    //1 2 3
    //v/v/
    //4 3 n
    //.   rt
    //.     l
    //1 2 3 n
    //.   v/
    //5 4 3 n
    //.     rt
    ListNode* reverse(ListNode* head){
        ListNode* pre=nullptr;
        while(head){
            ListNode* tmp=head->next;
            head->next=pre;
            pre=head;
            head=tmp;
        }
        return pre;
    }
};