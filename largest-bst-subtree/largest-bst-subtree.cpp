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
    int largestBSTSubtree(TreeNode* root) {
      ans=0;
      dfs(root);
      return ans;
    }
  vector<int> dfs(TreeNode* root){
    if(root==nullptr) return {INT_MAX,INT_MIN,0};
    vector<int>l=dfs(root->left);
    vector<int>r=dfs(root->right);
    if((l[2]==-1 || r[2]==-1)) return {INT_MIN,INT_MAX,-1};
    if(root->val>l[1] && root->val <r[0]){
      int size=l[2]+r[2]+1;
      ans=max(ans,size);
      return {l[0]==INT_MAX?root->val:l[0],r[1]==INT_MIN?root->val:r[1],size};
    }else{
      return {INT_MIN,INT_MAX,-1};
    }
  }
};