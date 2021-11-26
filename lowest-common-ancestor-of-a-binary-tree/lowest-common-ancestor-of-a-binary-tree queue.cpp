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
    unordered_map<TreeNode*,TreeNode*>map;
    map[root]=nullptr;
    queue<TreeNode*>q0;
    q0.push(root);
    while(map.find(q)==map.end() || map.find(p)==map.end()){
      auto cur=q0.front();
      q0.pop();
      if(cur->left!=nullptr){
        q0.push(cur->left);
        map[cur->left]=cur;
      }
      if(cur->right!=nullptr){
        q0.push(cur->right);
        map[cur->right]=cur;
      }
    }
    unordered_set<TreeNode*>set;
    while(p!=nullptr) set.insert(p),p=map[p];
    while(q!=nullptr){
      if(set.find(q)!=set.end()) return q;
      q=map[q];
    }
    return nullptr;
  }
};
