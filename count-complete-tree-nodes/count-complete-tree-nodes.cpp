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
    TreeNode* root1=root;
    int level=-1;
    while(root1!=nullptr) { //root is level 0
      root1=root1->left;
      level++;
    }
    int left=(1<<level);
    int right=(1<<(level+1))-1;
    while(left<right){
      int mid=left+(right-left+1)/2;
      root1=root;
      if(exist(mid,root1,level)) left=mid;
      else right=mid-1;
    }
    return left;
  }
  bool exist(int idx,TreeNode* root,int level){
    int mask=(1<<(level-1)); //don't consider the first bit
    while(root!=nullptr && mask>0){
      if(idx&mask) root=root->right;
      else root=root->left;
      mask>>=1;
    }
    return root!=nullptr;
  }
};