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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(root==nullptr) return {};
      queue<TreeNode*>q0;
      vector<vector<int>>ans;
      q0.push(root);
      while(!q0.empty()){
        int levelSize=q0.size();
        vector<int>level;
        while(levelSize--){
          TreeNode* cur=q0.front();
          q0.pop();
          level.push_back(cur->val);
          if(cur->left!=nullptr) q0.push(cur->left);
          if(cur->right!=nullptr) q0.push(cur->right);
        }
        ans.push_back(level);
      }
      return ans;
    }
};