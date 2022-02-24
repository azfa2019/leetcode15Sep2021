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
    ListNode* sortList(ListNode* head) {
        auto dummy=new ListNode();
        dummy->next=head;
        int len=0;
        for(auto p=head;p;p=p->next) len++;
        for(int size=1;size<len;size*=2){
            auto cur=dummy->next;
            auto tail=dummy;
            while(cur){
                auto left=cur;
                auto right=cut(left,size);
                cur=cut(right,size);
                tail->next=merge(left,right);
                while(tail->next) tail=tail->next;
            }
        }
        return dummy->next;
    }
    ListNode* cut(ListNode* head,int n){
        auto p=head;
        while(--n && p) p=p->next;
        if(!p) return nullptr;
        auto next=p->next;
        p->next=nullptr;
        return next;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        auto dummy=new ListNode();
        auto p=dummy;
        while(l1 && l2){
            if(l1->val<l2->val) p=p->next=l1,l1=l1->next;
            else p=p->next=l2,l2=l2->next;
        }
        p->next=l1?l1:l2;
        return dummy->next;
    }
};
