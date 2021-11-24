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
      ans=INT_MIN;
      dfs(root);
      return ans;
    }
  int dfs(TreeNode* root){
    if(root==nullptr) return 0;
    int left=dfs(root->left);
    int right=dfs(root->right);
    ans=max({ans,left+root->val+right,left+root->val,right+root->val,root->val});
    return max({left+root->val,right+root->val,root->val});
  }
};