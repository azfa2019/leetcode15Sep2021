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
    ListNode* removeNodes(ListNode* head) {
        stack<int>stk;
        ListNode* h=new ListNode(0);
        while(head){
            while(stk.size()&&head->val>stk.top()) stk.pop();
            stk.push(head->val);
            head=head->next;
        }
        ListNode* end=nullptr;
        while(stk.size()){
            ListNode* ne=new ListNode(stk.top(),end);
            stk.pop();
            end=ne;
        }
        return end;
    }
};