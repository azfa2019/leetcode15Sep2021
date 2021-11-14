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
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root==nullptr||subRoot==nullptr) return root==subRoot;
    if(helper(root,subRoot)) return true;
    else return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
  }
  bool helper(TreeNode* n1, TreeNode* n2){
    if(n1==nullptr ||n2==nullptr) return n1==n2;
    if(n1->val!=n2->val) return false;
    else return helper(n1->left,n2->left)&&helper(n1->right,n2->right); 
  }
};