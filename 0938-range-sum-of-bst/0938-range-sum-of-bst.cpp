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
    int res=0,l,r;
    int rangeSumBST(TreeNode* root, int low, int high) {
        l=low,r=high;
        helper(root);
        return res;
    }
    void helper(TreeNode* root){
        if(!root) return;
        int x=root->val;
        if(x>=l && x<=r) res+=x,helper(root->left),helper(root->right);
        if(x<l) helper(root->right);
        if(x>r) helper(root->left);
    }
};