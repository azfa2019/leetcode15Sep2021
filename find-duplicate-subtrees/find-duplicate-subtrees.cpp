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
  vector<TreeNode*>ans;
  int uid=0;
  map<tuple<int,int,int>,int>treeid;
  map<int,int>count;
  int dfs(TreeNode* node){
    if(node==nullptr) return -1;
    auto curtree=make_tuple(node->val,dfs(node->left),dfs(node->right));
    if(treeid.find(curtree)==treeid.end()) treeid[curtree]=uid,uid++;
    int curid=treeid[curtree];
    count[curid]++;
    if(count[curid]==2) ans.push_back(node);
    return curid;
  }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      dfs(root);
      return ans;
    }
};