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
  int longestUnivaluePath(TreeNode* root) {
    if(root==nullptr) return 0;
    int ans=0;
    helper(root,ans);
    return ans-1;
  }
  int helper(TreeNode* root,int& ans){
    if(root==nullptr) return 0;
    int left=helper(root->left,ans);
    int right=helper(root->right,ans);
    int llen=0,rlen=0;
    if(root->left!=nullptr && root->val==root->left->val) llen=left;
    if(root->right!=nullptr && root->val==root->right->val) rlen=right;
    ans=max(ans,llen+rlen+1);
    return max(llen,rlen)+1;
  }
};