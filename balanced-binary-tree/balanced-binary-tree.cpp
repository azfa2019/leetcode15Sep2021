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
    bool isBalanced(TreeNode* root) {
      if(root==nullptr) return true;
      return abs(height(root->left)-height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
  int height(TreeNode* node){
    if(node==nullptr) return 0;
    int left=height(node->left);
    int right=height(node->right);
    return max(left,right)+1;
  }
};