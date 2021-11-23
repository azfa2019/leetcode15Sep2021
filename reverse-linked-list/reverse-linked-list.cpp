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
  ListNode* reverseList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* pre=nullptr;
    while(head!=nullptr){
      ListNode* tmp=head->next;
      head->next=pre;
      pre=head;
      head=tmp;
    }
    return pre;
  }
};

//n<1<2<3<4<5 
//        p h t
//          p ht