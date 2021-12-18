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
        ListNode* fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* right=reverse(slow);
        ListNode* left=head;
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
//.      lt
// 1 2 3 n
// v/v/
// 5 4 3>n
//.      rt
//     l
// 1 2 3
// v/v
// 4 3 n
//.  r t
// right->next=3

// 1 2 3 4 n
//
// 1  2  3  4  n
// fs
//    s  f
//       s     f
// 1  2  3  4  5  n
// fs
//    s  f
//       s     f