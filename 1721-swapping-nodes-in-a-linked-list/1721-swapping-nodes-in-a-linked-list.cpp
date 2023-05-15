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
        ListNode* dum=new ListNode(0,head);
        ListNode* cur=dum;
        for(int i=1;i<k;i++) cur=cur->next;
        ListNode* left=cur->next;
        ListNode* pre1=cur;
        ListNode* pre2=dum;
        cur=cur->next->next;
        while(cur) cur=cur->next,pre2=pre2->next;
        ListNode* right=pre2->next;
        if(left==right) return head;
        else if(left==pre2) swapadjacent(pre1);
        else if(right==pre1) swapadjacent(pre2);
        else swapremote(pre1,pre2);
        return dum->next;
    }
    void swapadjacent(ListNode* pre){
        ListNode* n1=pre->next;
        ListNode* n2=n1->next;
        ListNode* post=n2->next;
        n1->next=post;
        n2->next=n1;
        pre->next=n2;
    }
    void swapremote(ListNode* pre1,ListNode* pre2){
        ListNode* n1=pre1->next;
        ListNode* n2=pre2->next;
        ListNode* post1=n1->next;
        ListNode* post2=n2->next;
        pre1->next=n2;
        n2->next=post1;
        pre2->next=n1;
        n1->next=post2;
    }
};