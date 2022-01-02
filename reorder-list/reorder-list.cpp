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
        ListNode* dummypre=new ListNode(0,head);
        ListNode* fast=dummypre, *slow=dummypre;
        while(fast && fast->next) fast=fast->next->next,slow=slow->next;
        auto right=reverse(slow->next);
        auto left=head;
        while(left && right){
            ListNode* tmp=left->next;
            left->next=right;
            left=tmp;
            tmp=right->next;
            right->next=left;
            right=tmp;
        }
        if(left->next) left->next=nullptr;
    }
    ListNode* reverse(ListNode* node){
        ListNode* pre=nullptr;
        while(node){
            ListNode* tmp=node->next;
            node->next=pre;
            pre=node;
            node=tmp;
        }
        return pre;
    }
};
//     l  
// 1 2 3>4>3 
// v/v/
// 5 4 n
//     rt
//   l 
// 1 2 3>n
// v/v/
// 4>3 n
//     rt
// 
// 