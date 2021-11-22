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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==nullptr) return nullptr;
    if(root->val>key) root->left= deleteNode(root->left,key);
    else if(root->val<key) root->right= deleteNode(root->right,key);
    else{
      if(root->left==nullptr) return root->right;
      else if(root->right==nullptr) return root->left;
      else{
        TreeNode* node=root->right;
        while(node->left!=nullptr) node=node->left;
        node->left=root->left;
        return root->right;
      }
    }
    return root;
  }
};