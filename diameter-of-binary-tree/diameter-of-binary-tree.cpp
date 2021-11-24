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
    int diameterOfBinaryTree(TreeNode* root) {
      helper(root);
      return ans;
    }
  int helper(TreeNode* root){
    if(root==nullptr) return 0;
    int left=helper(root->left);
    int right=helper(root->right);
    ans=max(ans,left+right);
    return max(left,right)+1;
  }
};