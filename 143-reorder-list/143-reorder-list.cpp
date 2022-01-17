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
        if(!head || head->next==nullptr) return;
        auto fast=head,slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        auto right=reverse(slow);
        ListNode *dummy=head,*left=head;
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
//     l
// 1 2 3 n
// 4 3 n
//   r
//       l
// 1 2 3 n
// 5 4 3 n
//     r