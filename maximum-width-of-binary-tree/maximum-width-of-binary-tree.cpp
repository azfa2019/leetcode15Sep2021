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
    int maxWidth=0;
    while(!q.empty()){
      int count=q.size();
      int start=q.front().second;
      int curPos;
      while(count--){
        TreeNode* cur=q.front().first;
        curPos=q.front().second;
        q.pop();
        if(cur->left!=nullptr) q.push({cur->left,2*curPos-2*start});
        if(cur->right!=nullptr) q.push({cur->right,2*curPos+1-2*start});
      }
      maxWidth=max(maxWidth,curPos-start+1);
    }
    return maxWidth;
  }
};