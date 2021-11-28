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
  unordered_map<string,int>count;
  vector<TreeNode*> ans;
  string dfs(TreeNode* node){
    if(node==nullptr) return "#";
    string cur= to_string(node->val)+","+dfs(node->left)+","+dfs(node->right);
    count[cur]++;
    if(count[cur]==2) ans.push_back(node);
    return cur;
  }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      dfs(root);
      return ans;
    }
};