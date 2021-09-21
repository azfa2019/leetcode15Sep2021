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
      //pre->next=head;
      while(head!=nullptr){
        ListNode* tmp=head->next;
        head->next=pre;
        pre=head;
        head=tmp;
      }
      return pre;
    }
};
// pre (null) <-head  2(tmp) ->3 ->4
// (null) <-head(pre)  2(head) ->3 
// (null) <-head(pre)  2(head) ->3 ->null
// (null) <-head<-  2(pre) ->3(head) ->null
// (null) <-head<-  2 <-3(pre) null(head)
//