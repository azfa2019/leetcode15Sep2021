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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l==r) return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* p=dummy;
        for(int i=0;i<l-1;i++) p=p->next;
        auto a=p,b=a->next,c=b->next;
        for(int i=l+1;i<=r;i++){
            auto d=c->next;
            c->next=b;
            b=c,c=d;
        }
        a->next->next=c;
        a->next=b;
        return dummy->next;
    }
};