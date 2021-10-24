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
    int countNodes(TreeNode* root) {
      if(root==nullptr) return 0;
      int res=0;
      int left=0;
      while(root!=nullptr){
        left=findDepth(root->left);
        int right=findDepth(root->right);
        if(left==right){
          res+=(1<<left);
          root=root->right;
        }else{
          res+=(1<<right);
          root=root->left;
        }
      }
      return res;
    }
  int findDepth(TreeNode* root){
    int depth=0;
    while(root!=nullptr){
      root=root->left;
      depth++;
    }
    return depth;
  }
};
