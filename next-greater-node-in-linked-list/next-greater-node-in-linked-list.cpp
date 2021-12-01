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
  vector<int> nextLargerNodes(ListNode* head) {
    ListNode* node=head;
    stack<pair<int,int>>stack;
    int idx=0;
    vector<int>ans;
    while(node!=nullptr){
      while(!stack.empty() && stack.top().first<node->val){
        ans[stack.top().second]=node->val;
        stack.pop();
      }
      stack.push({node->val,idx});
      ans.push_back(0);
      node=node->next;
      idx++;
    }
    return ans;
  }
};
// node stack idx ans
// 2.   2,0.  0   0
// 1    1,1   1   0
// 5. pop: ans[2]