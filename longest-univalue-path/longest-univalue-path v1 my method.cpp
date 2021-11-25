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
    int longestUnivaluePath(TreeNode* root) {
      int ans=0;
      helper(root,ans);
      return ans;
    }
  pair<int,int>helper(TreeNode* root,int& ans){
    if(root==nullptr) return {-1001,0};
    auto left=helper(root->left,ans);
    auto right=helper(root->right,ans);
    int ledge=root->val==left.first?left.second+1:0;
    int redge=root->val==right.first?right.second+1:0;
    ans=max(ans,ledge+redge);
    return {root->val,max(ledge,redge)};
  }
};
