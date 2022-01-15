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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
    bool dfs(TreeNode* node,long long low,long long high){
        if(!node) return true;
        return (node->val<high && node->val>low && dfs(node->left,low,node->val) && dfs(node->right,node->val,high));
    }
};