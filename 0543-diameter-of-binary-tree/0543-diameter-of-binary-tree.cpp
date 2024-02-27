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
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return ans-1;
    }
    int helper(TreeNode* node){
        if(!node) return 0;
        int l=helper(node->left),r=helper(node->right);
        ans=max(ans,l+r+1);
        return max(l,r)+1;
    }
};