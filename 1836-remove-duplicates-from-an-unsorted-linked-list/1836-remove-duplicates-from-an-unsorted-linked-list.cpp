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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int,int>hash;
        for(auto cur=head;cur;cur=cur->next) hash[cur->val]++;
        ListNode dummy(0,head);
        ListNode *cur=&dummy;
        while(cur){
            while(cur->next && hash.count(cur->next->val) && hash[cur->next->val]>1)
                cur->next=cur->next->next;
            cur=cur->next;
        }
        return dummy.next;
    }
};