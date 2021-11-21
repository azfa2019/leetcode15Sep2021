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
  int ans;
  public:
  int maxPathSum(TreeNode* root) {
    this->ans=INT_MIN;
    helper(root);
    return ans;
  }
  int helper(TreeNode*root){
    if(root==nullptr) return 0;
    int left=helper(root->left);
    if(left<0) left=0;
    
    int right=helper(root->right);
    if(right<0) right=0;
    ans=max(ans,left+right+root->val);
    return max(left,right)+root->val;
  }
};