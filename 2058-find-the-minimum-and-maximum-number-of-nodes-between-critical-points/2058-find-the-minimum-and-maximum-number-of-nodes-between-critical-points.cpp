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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *a = head, *b = head->next, *c = head->next->next;
        int first = 0, last = 0, minDis = INT_MAX;
        for (int i = 1, prev = 0; c != nullptr; ++i) { // Traversing the list to find critical points
            if ((a->val < b->val && b->val > c->val) || (a->val > b->val && b->val < c->val)) {
                if (first == 0) {
                    first = i; // First critical point position
                }
                last = i; // Last critical point position
                if (prev > 0 && i - prev < minDis) {
                    minDis = i - prev; // Update the minimum difference between adjacent critical points
                }
                prev = i;
            }
            a = b;
            b = c;
            c = c->next;
        }
        if (first == last) { // Less than two critical points
            return {-1, -1};
        }  
    return {minDis, last - first};
    }
};