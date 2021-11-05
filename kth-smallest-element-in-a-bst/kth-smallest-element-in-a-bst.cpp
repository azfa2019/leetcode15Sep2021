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
      int leftsize=helper(root->left);
      if(leftsize==k-1) return root->val;
      else if(leftsize>k-1) return kthSmallest(root->left,k);
      else return kthSmallest(root->right,k-leftsize-1);
    }
  int helper(TreeNode* node){
    if(node==nullptr) return 0;
    int left=helper(node->left);
    int right=helper(node->right);
    return left+right+1;
  }
};