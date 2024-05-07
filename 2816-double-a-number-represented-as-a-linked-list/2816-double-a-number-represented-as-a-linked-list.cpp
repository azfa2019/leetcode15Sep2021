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
    ListNode* reverse(ListNode* head){
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            auto ne=cur->next;
            cur->next=pre;
            pre=cur;
            cur=ne;
        }
        return pre;
    }
    ListNode* doubleIt(ListNode* head) {
        auto headR=reverse(head);
        auto dummy=headR;
        int t=0;
        while(headR){
            int d=headR->val;
            headR->val=(d*2+t)%10;
            t=(d*2)/10;
            headR=headR->next;
        }
        
        auto head2=reverse(dummy);
        if(t) {
            ListNode* head3=new ListNode(t,head2);
            return head3;
        }
        return head2;
    }
};