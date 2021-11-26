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
  int kthSmallest(TreeNode* root, int k) {
    int left=helper(root->left);
    if(left==k-1) return root->val;
    else if(left>k-1) return kthSmallest(root->left,k);
    else return kthSmallest(root->right,k-left-1);
  }
  int helper(TreeNode* root){
    if(root==nullptr) return 0;
    int left=helper(root->left);
    int right=helper(root->right);
    return left+right+1;
  }

};