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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto pre=head,cur=head->next;
        while(cur){
            int d=gcd(pre->val,cur->val);
            ListNode* t=new ListNode(d,cur);
            pre->next=t;
            pre=cur,cur=cur->next;
        }
        return head;
    }
    int gcd(int a,int b){
        return b?gcd(b,a%b):a;
    }
};