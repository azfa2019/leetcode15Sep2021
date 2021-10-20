/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
  int count,maxCount,num;
  vector<int> findMode(TreeNode* root) {
    vector<int>ans;
    helper(root,ans);
    return ans;
  }
  void helper(TreeNode* root,vector<int>&ans){
    if(root==nullptr) return;
    helper(root->left,ans);
    
    if(num==root->val) count++;
    else count=1,num=root->val;
    
    if(count>maxCount){
      maxCount=count;
      ans={root->val};
    }else if(count==maxCount){
      ans.push_back(root->val);
      num=root->val;
    }
    helper(root->right,ans);
  }
};