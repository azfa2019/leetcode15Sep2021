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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyPre=new ListNode();
        ListNode* l0=dummyPre;
        int t=0;
        while(l1 || l2 ||t){
            if(l1) t+=l1->val;
            if(l2) t+=l2->val;
            l0->next=new ListNode(t%10);
            t/=10;
            l0=l0->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return dummyPre->next;
    }
};