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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummypre=new ListNode();
        dummypre->next=head;
        auto pre=dummypre;
        if(!head) return head;
        if(!head->next) return head;
        ListNode* tmp=new ListNode();
        ListNode* n1=head,*n2=head->next;

        while(n1 && n1->next){
            n1->next=n2->next;
            n2->next=n1;
            pre->next=n2;
            pre=n1;
            n1=n1->next;
            if(n1) n2=n1->next;
        }
        return dummypre->next;
    }
};
