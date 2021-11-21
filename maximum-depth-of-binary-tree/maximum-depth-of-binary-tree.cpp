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
    int maxDepth(TreeNode* root) {//00
      if(root==nullptr) return 0;
      int level=1,maxLevel=INT_MIN;
      helper(root,level,maxLevel);
      return maxLevel;
    }
  void helper(TreeNode* root,int level,int& maxLevel){
    if(root==nullptr) return;
    maxLevel=max(maxLevel,level);
    //cout<<maxLevel<<endl;
    helper(root->left,level+1,maxLevel);
    helper(root->right,level+1,maxLevel);
  }
};