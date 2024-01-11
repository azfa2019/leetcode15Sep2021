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
    int ans=0;
    int maxAncestorDiff(TreeNode* root) {
        helper(root,root->val,root->val);
        return ans;
    }
    void helper(TreeNode* node,int mn,int mx){
        if(!node) {
            ans=max(ans,mx-mn);
            return;
        }
        mn=min(mn,node->val);
        mx=max(mx,node->val);
        helper(node->left,mn,mx);
        helper(node->right,mn,mx);
    }
};