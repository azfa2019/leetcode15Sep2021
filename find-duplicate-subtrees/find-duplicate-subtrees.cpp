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
  vector<TreeNode*>ans;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      collect(root);
      return ans;
    }
  string collect(TreeNode* node){
    if(node==nullptr) return "#";
    string serial=to_string(node->val)+","+collect(node->left)+","+collect(node->right);
    count[serial]++;
    if(count[serial]==2) ans.push_back(node);
    return serial;
  }
};