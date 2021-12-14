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
    int ans,low,high;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low=low,this->high=high;
        helper(root);
        return ans;
    }
    void helper(TreeNode* node){
        if(node==nullptr) return;
        if(node->val<=high && node->val>=low) ans+=node->val;
        helper(node->left);
        helper(node->right);
    }
};