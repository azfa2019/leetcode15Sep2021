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
    int getDecimalValue(ListNode* head) {
        vector<int>bit;
        while(head!=nullptr){
            bit.push_back(head->val);
            head=head->next;
        }
        int ans=0;
        int n=bit.size();
        for(int i=0;i<n;i++){
            int j=n-1-i;
            if(bit[i]==1) ans^=(1<<j);
        }
        return ans;
    }
};