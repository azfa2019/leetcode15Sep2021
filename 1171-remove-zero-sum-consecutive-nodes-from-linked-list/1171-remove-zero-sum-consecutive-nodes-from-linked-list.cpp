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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>hash;
        auto dummy=new ListNode(0,head);
        hash[0]=dummy;
        int sum=0;
        for(auto p=head;p;p=p->next){
            sum+=p->val;
            if(hash.count(sum)){
                int cur=sum;
                for(auto q=hash[sum]->next;q!=p;q=q->next){
                    cur+=q->val;
                    hash.erase(cur);
                }
                hash[sum]->next=p->next;
            }else{
                hash[sum]=p;
            }
        }
        return dummy->next;
    }
};