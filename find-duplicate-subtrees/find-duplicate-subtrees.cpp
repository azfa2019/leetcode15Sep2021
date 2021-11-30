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
  unordered_map<string,int>key2id;
  unordered_map<string,int>key2count;
  vector<TreeNode*>ans;
  public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return ans;
  }
  int dfs(TreeNode* node){
    if(node==nullptr)return -1;
    string key=to_string(node->val)+"#"+to_string(dfs(node->left))+"#"+to_string(dfs(node->right));
    if(key2id.find(key)==key2id.end()){
      key2id[key]=key2id.size()+1;
      key2count[key]=1;
    }else{
      key2count[key]++;
      if(key2count[key]==2) ans.push_back(node);
    }
    return key2id[key];
  }
};