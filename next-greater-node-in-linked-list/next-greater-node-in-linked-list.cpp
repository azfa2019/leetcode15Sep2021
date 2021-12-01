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
    stack<pair<int,int>>stack; //val,index
    int idx=0;
    vector<int>ans;
    while(head!=nullptr){
      while(!stack.empty() && stack.top().first<head->val){
        ans[stack.top().second]=head->val;
        stack.pop();
      }
      ans.push_back(0);
      stack.push({head->val,idx});
      head=head->next;
      idx++;
    }
    return ans;
  }
};