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
        ListNode* cur=new ListNode();
        ListNode* pre=cur;

        while(!pq.empty()){
            ListNode*tmp=pq.top();
            cur->next=tmp;pq.pop();
            if(tmp!=nullptr && tmp->next!=nullptr) pq.push(tmp->next);
            cur=cur->next;
        }
        cur->next=nullptr;
        return pre->next;
    }
};
// cur > y
// pq [Y x x ]  
// l1 xxx
// l2 xxx
// l3 xxx