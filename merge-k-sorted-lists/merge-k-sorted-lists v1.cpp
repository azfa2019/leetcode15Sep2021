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
    class compare{
        public:
        bool operator()(ListNode*a, ListNode *b){
            return a->val>b->val;
        }
    };
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(auto l:lists) if(l!=nullptr) pq.push(l);
        ListNode* pre=new ListNode();
        ListNode* headpre=pre;

        while(!pq.empty()){
            ListNode*cur=pq.top();pq.pop();
            pre->next=cur;
            pre=pre->next;
            if(cur!=nullptr && cur->next!=nullptr) pq.push(cur->next);
        }
        pre->next=nullptr;
        return headpre->next;
    }
};
// pre > y
// pq [Y x x ]  
// l1 xxx
// l2 xxx
// l3 xxx
