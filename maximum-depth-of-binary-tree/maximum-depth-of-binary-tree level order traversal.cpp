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
    int maxDepth(TreeNode* root) {
      if(root==nullptr) return 0;
      queue<TreeNode*>q0;
      q0.push(root);
      int level=0;
      while(!q0.empty()){
        level++;
        int levelSize=q0.size();
        while(levelSize--){
          TreeNode* cur=q0.front();
          q0.pop();
          if(cur->left!=nullptr) q0.push(cur->left);
          if(cur->right!=nullptr) q0.push(cur->right);
        }
      }
      return level;
    }
};
