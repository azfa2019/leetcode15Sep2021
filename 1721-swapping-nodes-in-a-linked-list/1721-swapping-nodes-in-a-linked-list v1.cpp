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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        ListNode* h1=head;
        for(int i=0;i<k-1;i++) h1=h1->next;
        ListNode* h2=head;
        ListNode* h=h1;
        while(h->next) h=h->next,h2=h2->next;
        int tmp=h1->val;
        h1->val=h2->val;
        h2->val=tmp;
        return head;
    }
};
