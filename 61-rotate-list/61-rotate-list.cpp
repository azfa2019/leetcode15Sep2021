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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next|| k==0) return head;
        int n=0;
        ListNode* tail;
        for(auto p=head;p;p=p->next) tail=p,n++;
        k=k%n;
        auto p=head;
        for(int i=0;i<n-k-1;i++) p=p->next;
        tail->next=head;
        head=p->next;
        p->next=nullptr;
        return head;
    }
};