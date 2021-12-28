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
    struct compare{
        bool operator()(ListNode*a,ListNode*b){
            return a->val>b->val;
        }
    };
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(auto e:lists) if(e!=nullptr) pq.push(e);
        ListNode* pre=new ListNode();
        ListNode* dummyPre=pre;
        
        while(!pq.empty()){
            auto cur=pq.top();pq.pop();
            pre->next=cur;
            if(cur!=nullptr && cur->next!=nullptr) pq.push(cur->next);
            pre=pre->next;
        }
        return dummyPre->next;
    }
};