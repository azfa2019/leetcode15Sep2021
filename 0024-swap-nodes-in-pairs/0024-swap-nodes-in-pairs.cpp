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
        ListNode* dum=new ListNode(0,head);
        for(auto p=dum;p->next&&p->next->next;){
            auto a=p->next,b=a->next;
            p->next=b;
            a->next=b->next;
            b->next=a;
            p=a;
        }
        return dum->next;
    }
};