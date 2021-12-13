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
  int widthOfBinaryTree(TreeNode* root) {
    if(root==nullptr) return 0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,1});
    int width=0;
    while(!q.empty()){
      int count=q.size(),start=q.front().second,index;
      while(count--){
        TreeNode* tmp=q.front().first;
        index=q.front().second;
        q.pop();
        if(tmp->left) q.push({tmp->left,index*2-start*2});
        if(tmp->right) q.push({tmp->right,index*2+1-start*2});
      }
      width=max(width,index-start+1);
    }
    return width;
  }
};
