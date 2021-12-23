/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      unordered_map<TreeNode*,TreeNode*>mp;
      queue<TreeNode*>q0;
      mp[root]=nullptr;
      q0.push(root);
      while(!q0.empty()){
          auto cur=q0.front();q0.pop();
          if(cur->left) {
              q0.push(cur->left);
              mp[cur->left]=cur;
          }
          if(cur->right) {
              q0.push(cur->right);
              mp[cur->right]=cur;
          }
          if(mp.find(p)!=mp.end() && mp.find(q)!=mp.end()) break;
      }
      unordered_set<TreeNode*>st;
      while(p!=nullptr){
          st.insert(p);
          p=mp[p];
      }
      while(q!=nullptr){
          if(st.find(q)!=st.end()) return q;
          q=mp[q];
      }
      return nullptr;
  }
};