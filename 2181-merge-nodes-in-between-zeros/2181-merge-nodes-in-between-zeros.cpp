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
    ListNode* mergeNodes(ListNode* head) {
        auto cur=head;
        int sum;
        ListNode* dummy=new ListNode(-1);
        auto dummy0=dummy;
        for(;cur;cur=cur->next){
            if(cur->val==0){
                ListNode* node=new ListNode(sum);
                dummy->next=node;
                dummy=node;
                sum=0;
            }
            sum+=cur->val;
        }
        dummy->next=NULL;
        return dummy0->next->next;
    }
};