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
        bool operator()(ListNode*a, ListNode* b){
            return a->val>b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minHeap;
        for(auto node:lists){
            if(node) minHeap.push(node);
        }
        ListNode* pre=new ListNode(0);
        ListNode* dummyPre=pre;
        while(minHeap.size()){
            pre->next=minHeap.top(),minHeap.pop();
            if(pre->next->next) minHeap.push(pre->next->next);
            pre=pre->next;
        }
        return dummyPre->next;
    }
};