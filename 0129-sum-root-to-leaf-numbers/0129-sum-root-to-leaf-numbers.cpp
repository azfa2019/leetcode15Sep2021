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
    int ans;
    int sumNumbers(TreeNode* root) {
        if(root) helper(root,0);
        return ans;
    }
    void helper(TreeNode* root,int num){
        num=num*10+root->val;
        if(!root->left && !root->right) ans+=num;
        if(root->left) helper(root->left,num);
        if(root->right) helper(root->right,num);
    }
};