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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode * fast = head;
        while (k-1 != 0)    //快指针先走k-1步，到达第k个点
        {
            fast = fast -> next;
            k --;
        }
        ListNode* L = fast;
        ListNode* slow = head;  // 1 2 3 4 5 6 7 k=3  L=3
        while (fast -> next)    // slow=5 fast=7
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* R = slow;     // R=5

        int tmp = R->val;
        R->val = L->val;
        L->val = tmp;
        return head;

    }
};