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
  int ans=0;
  public:
  int sumNumbers(TreeNode* root) {
    dfs(root,0);
    return ans;
  }
  void dfs(TreeNode* node,int cur){
    cur=cur*10+node->val;
    if(node->left==nullptr && node->right==nullptr){
      ans+=cur;
      return;
    }else{
      if(node->left!=nullptr)
        dfs(node->left,cur);
      if(node->right!=nullptr)
        dfs(node->right,cur);
    }
  }
};