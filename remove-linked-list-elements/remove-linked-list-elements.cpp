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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* dummy=new ListNode(-1);
      dummy->next=head;
      ListNode*pre=dummy;
      while(pre!=nullptr && pre->next!=nullptr ){
        if(pre->next->val==val){
          ListNode*cur=pre->next;
          pre->next=cur->next;
        }else  pre=pre->next;
      }
      return dummy->next;
    }
};