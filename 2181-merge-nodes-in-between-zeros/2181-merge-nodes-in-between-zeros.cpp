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
        auto node=head->next;
        int sum=0;
        ListNode* ans=head;
        for(;node;node=node->next){
            if(node->val==0){
                ans->next->val=sum;
                ans=ans->next;
                sum=0;
            }else
            sum+=node->val;
        }
        ans->next=NULL;
        return head->next;
    }
};