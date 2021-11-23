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
    while(fast!=nullptr && fast->next!=nullptr) fast=fast->next->next,slow=slow->next;
    ListNode*left=head;
    ListNode*right=reverse(slow);
    while(left!=nullptr && right!=nullptr){
      ListNode* tmp=left->next;
      left->next=right;
      left=tmp;
      
      tmp=right->next;
      right->next=left;
      right=tmp;
    }
    
    if(left!=nullptr) left->next=nullptr;
  }
  ListNode* reverse(ListNode* head){
    ListNode* pre=nullptr;
    while(head!=nullptr) {
      ListNode* tmp=head->next;
      head->next=pre;
      pre=head;
      head=tmp;
    }
    return pre;
  }
};
//    
// 1 2 
// v/v
// 5 4>3>  n
//         rlt
// 1 2 
// v/v
// 4 3  n
//   l  rt
//       l
// 1  2  3  
// v /v /
// 5  4  n
//       rt

//1 2 3 4 
//f   f   f
//s s s

//1 2 3 4 5
//f   f   f 
//s s s

//  1 2 3 4 
//f   f   f
//s s s

//  1 2 3 4 5
//f   f   f   f
//s s s s
