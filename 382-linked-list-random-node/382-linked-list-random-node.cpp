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
    ListNode* node;
public:
    Solution(ListNode* head) {
        node=head;
    }
    
    int getRandom() {
        int cur;
        int count=0;
        for(auto h=node;h;h=h->next){
            count++;
            if(rand()%count==0) cur=h->val;
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */