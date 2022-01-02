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
    int longestConsecutive(TreeNode* root) {
        return dfs(root,nullptr,0);
    }
    int dfs(TreeNode* root,TreeNode* parent,int len){
        if(!root) return len;
        if(parent && parent->val+1==root->val) len++;
        else len=1;
        return max(len,max(dfs(root->left,root,len),dfs(root->right,root,len)));
    }
};