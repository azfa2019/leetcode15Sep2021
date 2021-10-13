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
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n=preorder.size();
    return helper(0,n-1,preorder);
  }
  TreeNode* helper(int l,int r,vector<int>& preorder){
    if(l==r) {
      TreeNode* node=new TreeNode(preorder[l]);
      return node;
    }
    if(l>r) return nullptr;
    TreeNode* root=new TreeNode(preorder[l]);
    int pos=l+1;
    while(pos<preorder.size() && preorder[pos]<preorder[l]) pos++;
    root->left=helper(l+1,pos-1,preorder);
    root->right=helper(pos,r,preorder);
    return root;
  }
};