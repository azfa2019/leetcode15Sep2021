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
    int sumOfLeftLeaves(TreeNode* root) {
      return root==nullptr?0:dfs(root);
    }
  int dfs(TreeNode* node){
    int ans=0;
    if(node->left!=nullptr) ans+=isLeaf(node->left)?node->left->val:dfs(node->left);
    if(node->right!=nullptr && !isLeaf(node->right)) ans+=dfs(node->right);
    return ans;
  }
  bool isLeaf(TreeNode* node){
    return node->left==nullptr && node->right==nullptr;
  }
};