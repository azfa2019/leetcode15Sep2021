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
    int pathSum(TreeNode* root, int sum) {
      if(root==nullptr) return 0;
      int ret=rootSum(root,sum);
      ret+=pathSum(root->left,sum);
      ret+=pathSum(root->right,sum);
      return ret;
    }
  int rootSum(TreeNode*root,int sum){
    if(root==nullptr) return 0;
    int ret=0;
    if(root->val==sum) ret++;
    ret+=rootSum(root->left,sum-root->val);
    ret+=rootSum(root->right,sum-root->val);
    return ret;
  }
};