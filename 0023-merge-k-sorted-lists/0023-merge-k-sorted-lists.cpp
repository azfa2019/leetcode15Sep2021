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
    struct cmp{
        bool operator()(ListNode* a,ListNode*b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>heap;
        ListNode* dummy=new ListNode(),*tail=dummy;
        for(auto l:lists){
            if(l) heap.push(l);
        }
        while(heap.size()){
            auto t=heap.top();heap.pop();
            tail=tail->next=t;
            if(tail->next) heap.push(tail->next);
        }
        return dummy->next;
    }
};