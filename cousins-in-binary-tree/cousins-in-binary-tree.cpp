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
  bool isCousins(TreeNode* root, int x, int y) {
    int dx=findDepth(root,x,y,0);
    int dy=findDepth(root,y,x,0);
    if(dx==dy && dx!=-1 ) return true;
    return false;
  }
  int findDepth(TreeNode* node,int x, int y, int depth){
    if(node==nullptr) return 0;
    if(node->left!=nullptr && node->right!=nullptr && node->left->val==x&&node->right->val==y) return -1;
    if(node->val==x) return depth;
    int left=findDepth(node->left,x,y,depth+1);
    int right=findDepth(node->right,x,y,depth+1);
    return left==0?right:left;
  }
};