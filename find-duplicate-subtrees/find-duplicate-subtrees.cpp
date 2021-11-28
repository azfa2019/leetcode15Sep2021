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
  map<tuple<int,int,int>,int>tree;
  map<int,int>count;
  int uid=0;
  int lookup(TreeNode* node){
    if(node==nullptr) return -1;
    auto t=make_tuple(node->val,lookup(node->left),lookup(node->right));
    if(tree.find(t)==tree.end()) tree[t]=uid,uid++;
    int curid=tree[t];
    count[curid]++;
    if(count[curid]==2) ans.push_back(node);
    return curid;
  }
  public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    lookup(root);
    return ans;
  }
};