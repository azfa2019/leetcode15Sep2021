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
    int ans;
public:
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return ans;
    }
    void helper(TreeNode* node,int cur){
        if(!node) return;
        if(node->left==nullptr && node->right==nullptr) {
            ans+=cur*2+node->val;
            return;
        }
        helper(node->left,cur*2+node->val);
        helper(node->right,cur*2+node->val);
    }
};